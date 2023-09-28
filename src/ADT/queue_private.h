#ifndef QUEUE_PRIVATE_H
#define QUEUE_PRIVATE_H

#include <stddef.h>
#include <ADT/queue.h>

struct queue_node_s {
    void *data;
    struct queue_node_s *next;
    struct queue_node_s *prev;
};

typedef struct queue_node_s queue_node_t;

struct queue_s {
    queue_node_t *head;
    queue_node_t *tail;
    size_t size;
};

#endif