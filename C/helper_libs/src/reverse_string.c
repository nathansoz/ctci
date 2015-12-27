#include "reverse_string.h"

void reverse_string(char* str)
{
    if(str == NULL)
        return;

    int length = strlen(str);

    if(length == 0)
        return;

    char* buffer = malloc(length * sizeof(char));

    for(int i = 0; i < length; i++)
    {
        buffer[(length - 1) - i] = str[i];
    }

    for(int j = 0; j < length; j++)
        str[j] = buffer[j];

    free(buffer);
}