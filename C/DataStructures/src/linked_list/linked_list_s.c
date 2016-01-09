#include <string.h>
#include "linked_list/linked_list_s.h"
#include "linked_list/node_s.h"



struct _linked_list_s_impl
{
    struct node_s*  head;
    freeFunction    freeFn;
    size_t          nodeDataSize;
    uint32_t        count;
};

struct linked_list_s* lls_init(size_t nodeDataSize, freeFunction freeFn)
{
    struct linked_list_s* list = malloc(sizeof(struct linked_list_s));

    if(list == NULL)
        return NULL;

    list->_impl = malloc(sizeof(struct _linked_list_s_impl));

     if(list->_impl == NULL)
     {
         free(list);
         return NULL;
     }

    list->_impl->head = NULL;
    list->_impl->freeFn = freeFn;
    list->_impl->nodeDataSize = nodeDataSize;
    list->_impl->count = 0;

    return list;
}
void lls_destroy(struct linked_list_s* list)
{
    while(list->_impl->count > 0)
        lls_delete_head(list);
    free(list->_impl);
    free(list);
}
struct node_s* _lls_alloc_node(struct linked_list_s* list, void* data)
{
    void* insertData = malloc(list->_impl->nodeDataSize);
    memcpy(insertData, data, list->_impl->nodeDataSize);

    struct node_s* insertNode = malloc(sizeof(struct node_s));
    insertNode->data = insertData;
    insertNode->next = NULL;

    return insertNode;
}
void _lls_delete_node(struct node_s* deleteNode, freeFunction freeFn)
{
    if(freeFn == NULL)
    {
        free(deleteNode->data);
        free(deleteNode);
    }
    else
    {
        freeFn(deleteNode->data);
        free(deleteNode);
    }
}
struct node_s* _lls_get_node_at(struct linked_list_s* list, uint32_t position)
{
    if(position > list->_impl->count)
        return NULL;

    struct node_s* cur = list->_impl->head;
    for(int i = 0; i < position; i++)
    {
        cur = cur->next;
    }

    return cur;
}
struct node_s* _lls_get_tail_node(struct linked_list_s* list)
{
    if(list->_impl->head == NULL)
        return NULL;

    struct node_s* cur = list->_impl->head;

    while(cur->next != NULL)
        cur = cur->next;

    return cur;
}
void lls_insert_head(struct linked_list_s* list, void* data)
{

    struct node_s* insertNode = _lls_alloc_node(list, data);

    if(list->_impl->head == NULL)
        list->_impl->head = insertNode;
    else
    {
        insertNode->next = list->_impl->head;
        list->_impl->head = insertNode;
    }

    list->_impl->count++;
}
void lls_insert_tail(struct linked_list_s* list, void* data)
{
    struct node_s* insertNode = _lls_alloc_node(list, data);
    struct node_s* tailNode = _lls_get_tail_node(list);

    if(tailNode == NULL)
        list->_impl->head = insertNode;
    else
        tailNode->next = insertNode;

    list->_impl->count++;
}
void lls_insert_at(struct linked_list_s* list, void* data, uint32_t position)
{
    if(position == 0)
        lls_insert_head(list, data);
    else if(position >= list->_impl->count)
        lls_insert_tail(list, data);
    else
    {
        struct node_s* insertNode = _lls_alloc_node(list, data);
        struct node_s* insertLoc = _lls_get_node_at(list, (position - 1));

        insertNode->next = insertLoc->next;
        insertLoc->next = insertNode;

    }

    list->_impl->count++;
}
void* lls_get_head(struct linked_list_s* list)
{
    return list->_impl->head->data;
}
void* lls_get_tail(struct linked_list_s* list)
{
    struct node_s* tail = _lls_get_tail_node(list);
    return tail->data;
}
void* lls_get_at(struct linked_list_s* list, uint32_t position)
{
    struct node_s* node = _lls_get_node_at(list, position);
    return node->data;
}
void lls_delete_head(struct linked_list_s* list)
{
    if(list->_impl->count == 0)
        return;
    else if(list->_impl->count == 1)
    {
        struct node_s* deleteNode = list->_impl->head;
        _lls_delete_node(deleteNode, list->_impl->freeFn);
        list->_impl->head = NULL;
        list->_impl->count--;
    }
    else
    {
        struct node_s* deleteNode = list->_impl->head;
        list->_impl->head = deleteNode->next;
        _lls_delete_node(deleteNode, list->_impl->freeFn);
        list->_impl->count--;
    }
}
void lls_delete_tail(struct linked_list_s* list)
{
    if(list->_impl->count == 0)
        return;
    else if(list->_impl->count == 1)
    {
        struct node_s* deleteNode = list->_impl->head;
        _lls_delete_node(deleteNode, list->_impl->freeFn);
        list->_impl->head = NULL;
        list->_impl->count--;
    }
    else
    {
        struct node_s* prevNode = _lls_get_node_at(list, (list->_impl->count - 2));
        struct node_s* deleteNode = prevNode->next;
        prevNode->next = NULL;
        _lls_delete_node(deleteNode, list->_impl->freeFn);
        list->_impl->count--;
    }

}
void lls_delete_at(struct linked_list_s* list, uint32_t position)
{
    if(list->_impl->count == 0)
        return;
    else if((position + 1) > list->_impl->count)
        return;
    else
    {
        struct node_s* prevNode = _lls_get_node_at(list, (position - 1));
        struct node_s* deleteNode = prevNode->next;
        prevNode->next = deleteNode->next;
        _lls_delete_node(deleteNode, list->_impl->freeFn);
        list->_impl->count--;
    }
}
uint32_t lls_count(struct linked_list_s* list)
{
    return list->_impl->count;
}

