#include "time_test.h"

void generateRandomArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        a[i] = rand() % INT_MAX;
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t n) {
    int i = (int) n - 1;
    for (int j = 0; i >= 0; --i, j++)
        a[j] = i;
}

bool isOrdered(const int *a, const size_t n) {
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

void outputArray_(int *a, size_t n) {
    printf("[");
    for (int i = 0; i < n; ++i)
        printf("{%d}", a[i]);

    printf("]\n");
}

void checkTime(void (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size, char *experimentName) {
    static size_t runCounter = 1;
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time)

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    SortFunc sorts[] = {
            {bubbleSort,    "bubbleSort"},
            {insertionSort, "insertionSort"},
            {selectionSort, "selectionSort"},
            {combsort,      "combsort"},
            {shellSort,     "shellSort"},
            {radixSort,     "radixSort"}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GenerationFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("-----------------");
        printf("Size: %zu\n", size);
        for (int i = 0; i < FUNCS_N; ++i) {
            for (int j = 0; j < CASES_N; ++j) {
                static char filename[128];
                sprintf(filename, "%s_%s_time", sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort, generatingFuncs[j].generate, size, filename);
            }
        }
        printf("\n");
    }
}

void checkCountComparisonOperations(long long (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size, char *experimentName) {
    static size_t runCounter = 1;
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    long long countComparisonOperations = {
            sortFunc(innerBuffer, size)
    };

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Count comparison operations: %lld\n", countComparisonOperations);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, countComparisonOperations);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void countComparisonOperationsExperiment() {
    SortFuncComparisonOperations sorts[] = {
            {getBubbleSortNComp,    "bubbleSort"},
            {getInsertionSortNComp, "insertionSort"},
            {getSelectionSortNComp, "selectionSort"},
            {getCombSortNComp,      "combsort"},
            {getShellSortNComp,     "shellSort"},
            {getRadixSortNComps,    "radixSort"}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GenerationFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("-----------------");
        printf("Size: %zu\n", size);
        for (int i = 0; i < FUNCS_N; ++i) {
            for (int j = 0; j < CASES_N; ++j) {
                static char filename[128];
                sprintf(filename, "%s_%s_comparisonOperations", sorts[i].name, generatingFuncs[j].name);
                checkCountComparisonOperations(sorts[i].sort, generatingFuncs[j].generate, size, filename);
            }
        }
        printf("\n");
    }
}
