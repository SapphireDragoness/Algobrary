#ifndef STACK_H
#define STACK_H

#include <ADT/stack.h>
#include <stddef.h>

typedef struct stack_s *stack_t;

stack_t stack_create();

int stack_destroy(stack_t stack, int destroy_data);

int stack_push(stack_t stack, void *data);

int stack_pop(stack_t stack, int destroy_data);

void* stack_top(const stack_t stack);

int stack_is_empty(const stack_t stack);

size_t stack_size(const stack_t stack);

int stack_clear(stack_t stack, int destroy_data);

#endif