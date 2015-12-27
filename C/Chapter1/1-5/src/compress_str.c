#include "compress_str.h"

// '0' == 48
// '9' == 57

int compress_str(char* in, char** out)
{
    if(*out != NULL)
        return -1;

    size_t inputLength = strlen(in);
    char* buffer = malloc((inputLength * sizeof(char)) + 1);

    int i = 0; int j = 0;
    while(i < inputLength)
    {
        char current = in[i];
        buffer[j++] = in[i++];

        int count = 1;
        while(in[i] == current)
        {
            count++; i++;
        }
        if(count == 1)
            continue;
        else if(count < 10)
            buffer[j++] = (char)(count + 48);
        else
        {
            size_t maxRepeatPlaces = (inputLength / 10) + 1;
            char* countBuffer = malloc((maxRepeatPlaces * sizeof(char)) + 1);
            int k = 0;
            do
            {
                int rem = count % 10;
                count = count / 10;
                countBuffer[k++] = ((char)(rem + 48));
            }
            while(count != 0);

            countBuffer[k] = '\0';
            reverse_string(countBuffer);

            for(int l = 0; l < strlen(countBuffer); l++)
                buffer[j++] = countBuffer[l];
        }
    }
    buffer[j] = '\0';

    //now we can conserve memory by only returning a string that is malloc'ed for what it needs
    size_t retStrLen = strlen(buffer);
    char* outString = malloc((retStrLen * sizeof(char)) + 1);

    for(i = 0; i < retStrLen; i++)
        outString[i] = buffer[i];
    outString[retStrLen] = '\0';
    free(buffer);

    *out = outString;

    return retStrLen;
}