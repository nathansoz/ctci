#include <stdio.h>
#include "linked_list/linked_list_s.h"
#include "ll_remove_duplicates.h"


int main()
{
    void print_int_list(struct linked_list_s* list)
    {
        for(uint32_t i = 0; i < lls_count(list); i++)
        {
            int* it = lls_get_at(list, i);

            printf("%d ", *it);
        }
        printf("\n");
    }

    int testEquInt(void* a, void* b)
    {
        if(a == NULL || b == NULL)
            return 0;

        if(*(int*)a == *(int*)b)
            return 1;

        return 0;

    }

    struct linked_list_s* list = lls_init(sizeof(int), NULL);
    for(int i = 0; i < 10; i++)
    {
        lls_insert_tail(list, &i);
        lls_insert_tail(list, &i);
    }

    print_int_list(list);
    testEqu testFunc;
    testFunc = &testEquInt;
    ll_remove_duplicates(list, testFunc);
    print_int_list(list);
    lls_destroy(list);

}