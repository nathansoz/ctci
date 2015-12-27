// Nathan Sosnovske
// Cracking the Coding Interview (5th ed)
// Question 1-8
//
// Assume you have a function that can determine if one string is a substring of another.
// Find a way to tell if one string is a rotation of another only using one call to the substring function

#include <stdio.h>

#include "strrot.h"

int main()
{
    char* string1a = "waterbottle";
    char* string1b = "erbottlewat";

    char* string2a = "catsarekool";
    char* string2b = "coolcatsare";

    if(strrot(string1a, string1b) == 1)
        printf("%s is a rotation of %s\n", string1a, string1b);
    else
        printf("%s is NOT a rotation of %s\n", string1a, string1b);

    if(strrot(string2a, string2b) == 1)
        printf("%s is a rotation of %s\n", string2a, string2b);
    else
        printf("%s is NOT a rotation of %s\n", string2a, string2b);

    return 0;
}