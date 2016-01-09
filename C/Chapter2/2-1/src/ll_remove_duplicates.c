#include "ll_remove_duplicates.h"

#include <stdint.h>

void ll_remove_duplicates(struct linked_list_s* list, testEqu equFunc)
{
    uint32_t i = 0;
    uint32_t j = 1;

    while(i < lls_count(list))
    {
        while(j < lls_count(list))
        {
            int * first = lls_get_at(list, i);
            int * second = lls_get_at(list, j);

            if(equFunc(first, second) == 1)
                lls_delete_at(list, j);
            else
                j++;
        }

        i++;
        j = i + 1;
    }
}