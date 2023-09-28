#ifndef STACK_PRIVATE_H
#define STACK_PRIVATE_H

#include <stddef.h>
#include <ADT/stack.h>

struct stack_node_s {
    void *data;
    struct stack_node_s *next;
};

typedef struct stack_node_s stack_node_t;

struct stack_s {
    stack_node_t *top;
    size_t size;
};

#endif