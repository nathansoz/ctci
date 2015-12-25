// Nathan Sosnovske
// Cracking the Coding Interview (5th ed)
// Question 1-4
// 
// Replace all spaces in a string with %20, assuming that there is room at
//   the end of the string to move the string forward

#include "print_array.h"
#include "urlify.h"


int main()
{
    char testStr[] = "Test this string              ";
    int len = 16;
    print_char_array(testStr, strlen(testStr));
    urlify(testStr, len);
    print_char_array(testStr, strlen(testStr));
    return 0;
}