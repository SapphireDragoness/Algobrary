#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_s *linked_list_t;

linked_list_t linked_list_create();

int linked_list_destroy(linked_list_t linked_list, int destroy_data);

int linked_list_clear(linked_list_t linked_list, int destroy_data);

int linked_list_ins_next(linked_list_t linked_list, void *data);

int linked_list_rem_next(linked_list_t linked_list, int destroy_data);

void* linked_list_head(const linked_list_t list);

void* linked_list_tail(const linked_list_t list);

size_t linked_list_size(const linked_list_t list);

int linked_list_is_empty(const linked_list_t list);

#endif

