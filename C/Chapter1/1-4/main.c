// Nathan Sosnovske
// Cracking the Coding Interview (5th ed)
// Question 1-4
// 
// Replace all spaces in a string with %20, assuming that there is room at
//   the end of the string to move the string forward

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_array(char arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%c", arr[i]);
    printf("\n");
}

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

int main()
{
    char testStr[] = "Test this string              ";
    int len = 16;
    print_array(testStr, strlen(testStr));
    urlify(testStr, len);
    print_array(testStr, strlen(testStr));
    return 0;
}