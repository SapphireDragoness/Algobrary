#include "quadratic_sorts_private.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(void *base, size_t n, size_t size, comparator_t cmp) {
    unsigned char *bp = base;
    for(size_t i = 1; i < n; i++) {
        size_t j = i;
        while((j > 0) && cmp(bp+j*size, bp+(j+1)*size) < 0) {
            swap(bp+j*size, bp+(j-1)*size, size);
            j--;
        }
    }
}

void bubble_sort(void *base, size_t n, size_t size, comparator_t cmp) {
    unsigned char *bp = base;
    int swapped = 1;

    for(size_t i = 0; i < n && swapped; i++) {
        swapped = 0;
        for(size_t j = 0; j < n-1; j++) {
            if(cmp(bp+j*size, bp+(j+1)*size) > 0)  {
                upo_swap(bp+j*size, bp+(j+1)*size, size);
                swapped = 1;
            }
        }
    }
}

void selection_sort(void *base, size_t n, size_t size, comparator_t cmp) {
    unsigned char *bp = base;
    
    for(size_t i = 0; i < n; i++) {

    }
}

void bidirectional_bubble_sort(void *base, size_t n, size_t size, comparator_t cmp) {
    unsigned char *bp = base;
    int swapped = 1;

    for(size_t i = 0; i < n && swapped; i++) {
        for(size_t j = 0; j < n-1; j++) {
            if(cmp(bp+j*size, bp+(j+1)*size) > 0)  {
                upo_swap(bp+j*size, bp+(j+1)*size, size);
                swapped = 1;
            }
        }
        if(swapped) {
            swapped = 0;
            for(size_t j = n-2; j > 0; j--) {
                if(cmp(bp+j*size, bp+(j-1)*size) < 0)  {
                    upo_swap(bp+j*size, bp+(j-1)*size, size);
                    swapped = 1;
                }
            }
        }
    }
}

void swap(void *pv1, void *pv2, size_t n) {
    if(pv1 == pv2) return;
    void *tmp = malloc(n);
    memmove(tmp, pv1, n);
    memmove(pv1, pv2, n);
    memmove(pv2, tmp, n);
    free(tmp);
}
