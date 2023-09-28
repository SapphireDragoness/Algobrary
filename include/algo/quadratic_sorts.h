#ifndef QUADRATIC_SORTS_H
#define QUADRATIC_SORTS_H

#include <stddef.h>

typedef int (*comparator_t)(const void*, const void*);

void insertion_sort(void *base, size_t n, size_t size, comparator_t cmp);

void bubble_sort(void *base, size_t n, size_t size, comparator_t cmp);

void selection_sort(void *base, size_t n, size_t size, comparator_t cmp);

void bidirectional_bubble_sort(void *base, size_t n, size_t size, comparator_t cmp);

#endif