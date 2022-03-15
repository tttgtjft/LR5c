#ifndef LR5C_TIME_TEST_H
#define LR5C_TIME_TEST_H

#include "../sort.h"
#include <time.h>

#define TIME_TEST(testCode, time){ \
clock_t start_time = clock();      \
testCode                           \
clock_t end_time = clock();        \
clock_t sort_time = end_time - start_time; \
time = (double) sort_time / CLOCKS_PER_SEC;\
}\

void generateRandomArray(int *a, size_t n);

void generateOrderedArray(int *a, size_t n);

void generateOrderedBackwards(int *a, size_t n);

void checkTime(void (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size, char *experimentName);

void timeExperiment();

#endif
