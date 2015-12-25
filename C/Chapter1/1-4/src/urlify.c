#include "urlify.h"

void urlify(char* str, int length)
{

    int spaces = 0;
    for(int i = 0; i < length; i++)
    {
        if(str[i] == ' ')
            spaces++;
    }

    int moveFactor = 2 * spaces;
    int i = length + moveFactor - 1;

    for(int j = length - 1; j >= 0; j--)
    {
        if(str[j] != ' ')
            str[i--] = str[j];
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}