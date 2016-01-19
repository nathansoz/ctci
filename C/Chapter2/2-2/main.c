#include <stdio.h>
#include "linked_list/linked_list_s.h"

// kth_from_last is trivial to implement, because I implemented a "get at" function for my
// linked list data structure. So all you need to do is take the size of the list, subtract the kth you want
// to get and return that value

void* kth_from_last(struct linked_list_s* list, uint32_t kth)
{
    uint32_t count = lls_count(list);
    uint32_t get_at = count - kth - 1;
    return lls_get_at(list, get_at);
}

void print_int_list(struct linked_list_s* list)
{
    for(uint32_t i = 0; i < lls_count(list); i++)
    {
        int* it = lls_get_at(list, i);

        printf("%d ", *it);
    }
    printf("\n");
}


int main()
{
    struct linked_list_s* list = lls_init(sizeof(int), NULL);

    for(int i = 0; i < 10; i++)
    {
        lls_insert_tail(list, &i);
    }

    print_int_list(list);

    int* test = kth_from_last(list, 3);

    printf("The 3rd element from last is %d (zero-indexed)\n", *test);

    lls_destroy(list);

    return 0;
}

