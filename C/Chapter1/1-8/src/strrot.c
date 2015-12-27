#include "strrot.h"

int strrot(char* str1, char* str2)
{
    if(str1 == NULL || str2 == NULL)
        return 0;

    char* buffer = malloc(((strlen(str1) * 2) + 1) * sizeof(char));
    strcpy(buffer, str1);
    strcat(buffer, str1);

    if(strstr(buffer, str2) != NULL)
        return 1;
    else
        return 0;
}