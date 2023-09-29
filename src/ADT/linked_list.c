#include "linked_list_private.h"
#include <stdio.h>
#include <stdlib.h>

linked_list_t linked_list_create() {
    linked_list_t linked_list = malloc(sizeof(linked_list_t));

    if(linked_list == NULL) {
        perror("Unable to allocate linked list");
        return NULL;
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

int linked_list_destroy(linked_list_t linked_list, int destroy_data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked list not allocated.")
        return -1;
    }

    linked_list_clear(linked_list, destroy_data);
    free(linked_list);
}

int linked_list_clear(linked_list_t linked_list, int destroy_data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked list not allocated.")
        return -1;
    }

    while(!linked_list_is_empty(linked_list)) {
        linked_list_node_t *node = linked_list->head;
        linked_list->head = linked_list->head->next;
        if(destroy_data) {
            free(node->data);
        }
        free(node);
        linked_list->size -= 1;
    }

    return 0;
}

int linked_list_ins_next(linked_list_t linked_list, void *data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked list not allocated.")
        return -1;
    }

    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));

    node->data = data;
    node -> next = 
}

int linked_list_rem_next(linked_list_t linked_list, int destroy_data);

void* linked_list_head(const linked_list_t list);

void* linked_list_tail(const linked_list_t list);

size_t linked_list_size(const linked_list_t list);

int linked_list_is_empty(const linked_list_t list);