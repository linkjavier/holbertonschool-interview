#ifndef MERGE_SORT
#define MERGE_SORT

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void merge(int *a, int n, int m);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif