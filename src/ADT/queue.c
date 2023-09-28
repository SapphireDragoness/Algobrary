#include "queue_private.h"
#include <stdio.h>
#include <stdlib.h>

queue_t queue_create() {
    queue_t queue = malloc(sizeof(queue_t));

    if(queue == NULL) {
        perror("Unable to allocate queue: ");
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int queue_destroy(queue_t queue, int destroy_data) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }

    queue_clear(queue, destroy_data);
    free(queue);

    return 0;
}

int queue_clear(queue_t queue, int destroy_data) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }
    
    while(!queue_is_empty(queue)) {
        queue_node_t *node = queue->head;
        queue->head = queue->head->next;
        if(destroy_data) {
            free(node->data);
        }
        free(node);
        queue->size -= 1;
    }

    return 0;
}

int queue_enqueue(queue_t queue, void *data) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }

    queue_node_t *node = malloc(sizeof(queue_node_t));

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    if(queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    }
    else{
        node->prev = queue->tail;
        queue->tail->next = node;
        queue->tail = queue->tail->next;
    }

    queue->size += 1;

    return 0;
}

int queue_dequeue(queue_t queue, int destroy_data) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }

    queue_node_t *node = queue->head;
    queue->head = node->next;

    if(queue->size == 1) {
        queue->head = NULL;
    }
    if(destroy_data) {
        free(node->data);
    }
    free(node);
    queue->size -= 1;

    return 0;
}

void* queue_peek(const queue_t queue) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }

    if(queue_is_empty) {
        return NULL;
    }

    return queue->head->data;
}

size_t queue_size(const queue_t queue) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }

    return queue->size;
}

int queue_is_empty(const queue_t queue) {
    if(queue == NULL) {
        fprintf(stderr, "Queue not allocated.");
        return -1;
    }

    return queue->size == 0 ? 1 : 0;
}