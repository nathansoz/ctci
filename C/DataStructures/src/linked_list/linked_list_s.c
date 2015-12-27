#include <string.h>
#include "linked_list/linked_list_s.h"
#include "linked_list/node_s.h"



struct _linked_list_s_impl
{
    struct node_s*  head;
    freeFunction    freeFn;
    int             nodeDataSize;
};

struct linked_list_s* lls_init(int nodeDataSize, freeFunction freeFn)
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

    return list;
}

void lls_insert_head(struct linked_list_s* list, void* data)
{
    void* insertData = malloc(list->_impl->nodeDataSize);
    memcpy(insertData, data, list->_impl->nodeDataSize);

    struct node_s* insertNode = malloc(sizeof(struct node_s));
    insertNode->data = insertData;
    insertNode->next = NULL;


    if(list->_impl->head == NULL)
        list->_impl->head = insertNode;
    else
    {
        insertNode->next = list->_impl->head;
        list->_impl->head = insertNode;
    }
}

void lls_insert_tail(struct linked_list_s* list, void* data)
{

}

void* lls_get_head(struct linked_list_s* list)
{
    return list->_impl->head;
}
void* lls_get_tail(struct linked_list_s* list)
{
    if(list->_impl->head == NULL)
        return NULL;

    struct node_s* cur = list->_impl->head;

    while(cur->next != NULL)
        cur = cur->next;

    return cur->data;
}
void* lls_get_at(struct linked_list_s* list, int position);

int lls_count(struct linked_list_s* list)
{
    if(list->_impl->head == NULL)
        return 0;

    int count = 1;
    struct node_s* cur = list->_impl->head;
    while(cur->next != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

