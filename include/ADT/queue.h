#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_s *queue_t;

queue_t queue_create();

int queue_destroy(queue_t queue, int destroy_data);

int queue_clear(queue_t queue, int destroy_data);

int queue_enqueue(queue_t queue, void *data);

int queue_dequeue(queue_t queue, int destroy_data);

void* queue_peek(const queue_t queue);

size_t queue_size(const queue_t queue);

int queue_is_empty(const queue_t queue);

#endif