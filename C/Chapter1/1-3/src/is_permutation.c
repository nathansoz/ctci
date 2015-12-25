#include "is_permutation.h"

int is_permutation(char* a, char* b)
{
    if(a == NULL || b == NULL)
        return 0;
        
    int length_a = strlen(a);
    int length_b = strlen(b);
 
    //A permutation of a set must be the same length of said set   
    if(length_a != length_b)
        return 0;
        
    quicksort((int*)a, length_a);
    quicksort((int*)b, length_b);
    
    for(int i = 0; i < length_a; i++)
    {
        if(a[i] != b[i])
            return 0;
    }
    
    return 1;
    
}