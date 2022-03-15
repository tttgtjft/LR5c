#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, size_t size) {
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
}

void insertionSort(int *arr, size_t size) {
    for (int i = 1; i < size; ++i) {
        int k = i;
        while (k > 0 && arr[k] < arr[k - 1]) {
            swap(&arr[k], &arr[k - 1]);

            k--;
        }
    }
}

void selectionSort(int *arr, size_t size) {
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

void combsort(int *arr, size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; j < size; ++i, j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
                swapped = 1;
            }
        }
    }
}

void shellSort(int *arr, size_t size) {
    int i, j, step;
    int temp;
    for (step = size / 2; step > 0; step /= 2) {
        for (i = step; i < size; i++) {
            temp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (temp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void radixSort_(int *a, int *n) {
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = a; j < n; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = n - 1; j >= a; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = a; j < n; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void radixSort(int *a, size_t n) {
    radixSort_(a, a + n);
}

long long getBubbleSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < n - 1; i++)
        for (size_t j = n - 1; ++nComps && j > i; j--)
            if (++nComps && a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
            }
    return nComps;
}

long long getSelectionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

long long getInsertionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t i = 1; ++nComps && i < n; i++) {
        int t = a[i];
        size_t j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
    return nComps;
}

long long getCombSortNComp(int *a, size_t n) {
    size_t step = n;
    int swapped = 1;
    long long nComps = 0;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < n; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
    return nComps;
}

long long getShellSortNComp(int *a, size_t n) {
    long long nComps = 0;
    size_t j;
    int tmp;
    for (size_t step = n / 2; ++nComps && step > 0; step /= 2)
        for (size_t i = step; ++nComps && i < n; i++) {
            tmp = a[i];
            for (j = i; ++nComps && j >= step; j -= step) {
                if (++nComps && tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
    return nComps;
}

long long getRadixSortNComps_(int *a, int *n) {
    long long nComps = 0;
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++)
            c[j] = 0;

        for (int *j = a; ++nComps && j < n; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; ++nComps && j < M; j++)
            c[j] += c[j - 1];

        for (int *j = n - 1; ++nComps && j >= a; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = a; ++nComps && j < n; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
    return nComps;
}

long long getRadixSortNComps(int *a, size_t n) {
    return getRadixSortNComps_(a, a + n);
}