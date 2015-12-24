#include "quicksort.h"

void swap(int* i, int* j)
{
    int tmp;
    tmp = *j;
    *j = *i;
    *i = tmp;
}

int partition(int* arr, int low, int hi)
{
    int partitionIndex = (hi + low) / 2;
    int partition = arr[partitionIndex];
    
    int i = low; int j = hi;
    
    while(i <= j)
    {
        while(arr[i] < partition)
            i++;
        while(arr[j] > partition)
            j--;
        if(i <= j)
        {
            swap(&(arr[i]), &(arr[j]));
            i++;
            j--;
        }
    }
    
    return i;
    
    
     
}

void quicksort_internal(int* arr, int low, int hi)
{
    int part = partition(arr, low, hi);
    if(low < part - 1)
        quicksort_internal(arr, low, part - 1);
    if(part < hi )
        quicksort_internal(arr, part, hi);
    
    
}


void quicksort(int* arr, int length)
{
    if(arr == NULL)
        return;
    if(length == 0 || length == 1)
        return;
        
    quicksort_internal(arr, 0, (length - 1));
    
}