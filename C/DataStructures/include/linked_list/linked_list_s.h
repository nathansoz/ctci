#pragma once

#include <stdlib.h>
#include <stdint.h>

struct _linked_list_s_impl;
typedef void (*freeFunction)(void *);

struct linked_list_s
{
    struct _linked_list_s_impl* _impl;
};

/* Inits a new linked list and returns pointer to it */
struct linked_list_s* lls_init(size_t nodeDataSize, freeFunction freeFn);
void lls_destroy(struct linked_list_s* list);


/* makes a copy of *data and places it at the head of the linked list */
void lls_insert_head(struct linked_list_s* list, void* data);
void lls_insert_tail(struct linked_list_s* list, void* data);
void lls_insert_at(struct linked_list_s* list, void* data, uint32_t position);

void* lls_get_head(struct linked_list_s* list);
void* lls_get_tail(struct linked_list_s* list);
void* lls_get_at(struct linked_list_s* list, uint32_t position);

void lls_delete_head(struct linked_list_s* list);
void lls_delete_tail(struct linked_list_s* list);
void lls_delete_at(struct linked_list_s* list, uint32_t position);

uint32_t lls_count(struct linked_list_s* list);



