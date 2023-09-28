#include "stack_private.h"
#include <stdio.h>
#include <stdlib.h>

stack_t stack_create() {
    stack_t stack = malloc(sizeof(stack));

    if(stack == NULL) {
        perror("Unable to allocate memory for the stack: ");
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

int stack_destroy(stack_t stack, int destroy_data) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }

    stack_clear(stack, destroy_data);
    free(stack);

    return 0;
}

int stack_push(stack_t stack, void *data) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }

    stack_node_t *node = malloc(sizeof(stack_node_t));

    if(node == NULL) {
        perror("Unable to allocate memory for stack node: ");
        return -1;
    }

    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size += 1;

    return 0;
}

int stack_pop(stack_t stack, int destroy_data) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }

    if(stack_is_empty(stack)) {
        fprintf(stderr, "Stack empty.");
        return -1;
    }

    stack_node_t *node = stack->top;
    stack->top = stack->top->next;
    stack->size = -1

    if(destroy_data) {
        free(node->data);
    }

    free(node);

    return 0;
}

void *stack_top(const stack_t stack) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }
    
    if(stack_is_empty(stack)) {
        return NULL;
    }

    return stack->top->data;
}

int stack_is_empty(const stack_t stack) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }

    return stack->size == 0 ? 1 : 0;
}

size_t stack_size(const stack_t stack) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }

    return stack->size;
}

int stack_clear(stack_t stack, int destroy_data) {
    if(stack == NULL) {
        fprintf(stderr, "Stack not allocated.");
        return -1;
    }

    while(!stack_is_empty(stack)) {
        stack_node_t *node = stack->top;
        stack->top = stack->top->next;
        if(destroy_data) {
            free(node->data);
        }
        free(node);
        stack->size -= 1;
    }

    return 0;
}