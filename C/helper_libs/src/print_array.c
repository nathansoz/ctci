#include "print_array.h"

void print_char_array(char arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%c", arr[i]);
    printf("\n");
}