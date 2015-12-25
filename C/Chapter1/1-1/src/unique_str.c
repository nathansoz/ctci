#include "unique_str.h"

//---------------------------------------------------------------------
int unique_str(char* string)
//  Determines if a string has all unique characters.
//  Inputs: Char* string
//
{
    int size = strlen(string);
    
    char* usedChars = malloc(size);
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(string[i] == usedChars[j])
            {
                free(usedChars);
                return 0;
            }
        }
        
        usedChars[i] = string[i];
    }
    
    free(usedChars);
    
    return 1;
}