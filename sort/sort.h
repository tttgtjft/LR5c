#ifndef LR5C_SORT_H
#define LR5C_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *arr, size_t size);

void insertionSort(int *arr, size_t size);

void selectionSort(int *arr, size_t size);

void combsort(int *arr, size_t size);

void shellSort(int *arr, size_t size);

void radixSort(int *arr, size_t size);

long long getBubbleSortNComp(int *a, size_t n);

long long getSelectionSortNComp(int *a, size_t n);

long long getInsertionSortNComp(int *a, size_t n);

long long getCombSortNComp(int *a, size_t n);

long long getShellSortNComp(int *a, size_t n);

long long getRadixSortNComps(int *a, size_t n);

#endif
