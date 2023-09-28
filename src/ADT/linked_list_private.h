#ifndef LINKED_LIST_PRIVATE_H
#define LINKED_LIST_PRIVATE_H

#include <stddef.h>
#include <ADT/linked_list.h>

struct linked_list_node_s {
    void *data;
    struct linked_list_node_s *next;
};

typedef struct linked_list_node_s linked_list_node_t;

struct linked_list_s {
    linked_list_node_t *head;
    linked_list_node_t *tail;
    size_t size;
};

#endif