#ifndef LR5C_SORT_H
#define LR5C_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

typedef struct SortFunc{
    void (*sort)(int *a, size_t n);
    char name[64];
} SortFunc;

typedef struct GenerationFunc{
    void (*generate)(int *a, size_t n);
    char name[64];
} GenerationFunc;

void bubbleSort(int *arr, size_t size);

void insertionSort(int *arr, size_t size);

void selectionSort(int *arr, size_t size);

void combsort(int *arr, size_t size);

void shellSort(int *arr, size_t size);

void radixSort(int *arr, size_t size);

#endif
