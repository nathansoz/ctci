// Nathan Sosnovske
// Cracking the Coding Interview (5th ed)
// Question 1-2
// 
// Algorithm that reverses a string


#include "revstr.h"
#include <stdio.h>

int main()
{
    char string[] = "Hello, computer!";
    revstr(string);
    
    printf("%s\n", string);
    printf("\n");
    
    return 0;
}