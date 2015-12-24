#include <stdio.h>
#include "is_permutation.h"

void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    char string_a[] = "abc";
    char string_b[] = "bca";
    char string_c[] = "abd";
    char string_d[] = "bcaa";
    
    int good = is_permutation(string_a, string_b);
    int bad1 = is_permutation(string_a, string_c);
    int bad2 = is_permutation(string_a, string_d);
    
    return 0;
}