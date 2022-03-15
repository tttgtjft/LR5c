#ifndef LR5C_TIME_TEST_H
#define LR5C_TIME_TEST_H

#include "../sort.h"
#include <time.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

#define TIME_TEST(testCode, time){ \
clock_t start_time = clock();      \
testCode                           \
clock_t end_time = clock();        \
clock_t sort_time = end_time - start_time; \
time = (double) sort_time / CLOCKS_PER_SEC;\
}\

typedef struct SortFunc{
    void (*sort)(int *a, size_t n);
    char name[64];
} SortFunc;

typedef struct GenerationFunc{
    void (*generate)(int *a, size_t n);
    char name[64];
} GenerationFunc;

typedef struct SortFuncComparisonOperations{
    long long (*sort)(int *a, size_t n);
    char name[64];
} SortFuncComparisonOperations;

void generateRandomArray(int *a, size_t n);

void generateOrderedArray(int *a, size_t n);

void generateOrderedBackwards(int *a, size_t n);

void timeExperiment();

void countComparisonOperationsExperiment();

#endif
