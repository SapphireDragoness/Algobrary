#include "linked_list_private.h"
#include <stdio.h>
#include <stdlib.h>

linked_list_t linked_list_create() {
    linked_list_t linked_list = malloc(sizeof(linked_list_t));

    if(linked_list == NULL) {
        perror("Unable to allocate linked linked_list");
        return NULL;
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

int linked_list_destroy(linked_list_t linked_list, int destroy_data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    linked_list_clear(linked_list, destroy_data);
    free(linked_list);
}

int linked_list_clear(linked_list_t linked_list, int destroy_data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
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

int linked_list_ins_next(linked_list_t linked_list, linked_list_node_t target, void *data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));

    node->data = data;
    node->next = NULL;

    if(target == NULL) {
        if(linked_list_size(linked_list) == 0) {
            linked_list->tail = node;
        }
        node->next = linked_list->head;
        linked_list->head = node;
    }
    else {
        if(target->next == NULL) {
            linked_list->tail = node;
        }
        node->next = target->next;
        target->next = node;
    }

    linked_list->size += 1;

    return 0;
}

int linked_list_rem_next(linked_list_t linked_list, linked_list_node_t target, int destroy_data) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    linked_list_node_t *old;

    if(linked_list_size(linked_list) == 0) {
        return -1;
    }

    if(target == NULL) {
        old = linked_list->head;
        linked_list->head = linked_list->head->next;
        if(linked_list_size(linked_list) == 1) {
            linked_list->tail = NULL;
        }
    }
    else {
        if(target->next == NULL) {
            return -1;
        }
        old = target->next;
        target->next = element->next->next;
        if(target->next == NULL) {
            linked_list->tail = target;
        }
    }
    if(destroy_data) {
        free(old->data);
    }

    free(node);
    linked_list->size -= 1;

    return 0;
}

void* linked_list_head(const linked_list_t linked_list) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    if(linked_list_is_empty) {
        return NULL;
    }

    return linked_list->head->data;
}

void* linked_list_tail(const linked_list_t linked_list) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    if(linked_list_is_empty) {
        return NULL;
    }

    return linked_list->tail->data;
}

size_t linked_list_size(const linked_list_t linked_list) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    return linked_list->size;
}

int linked_list_is_empty(const linked_list_t linked_list) {
    if(linked_list == NULL) {
        fprintf(stderr, "Linked linked_list not allocated.")
        return -1;
    }

    return linked_list->size == 0 ? 1 : 0;
}