// Nathan Sosnovske
// Cracking the Coding Interview (5th ed)
// Question 1-1
// 
// Algorithm that determines if a string has all unique characters

#include <stdio.h> //printf

#include "unique_str.h" //Implementation defined here


void print_result(int result)
{
    if(result == 0)
        printf("Not a unique string\n");
    else
        printf("String was unique\n");
}

int main()
{
    char* unique = "abcdefg";
    int result_unique = unique_str(unique);
    print_result(result_unique);
    
        
    char* same = "abccdefg";
    int result_same = unique_str(same);
    print_result(result_same);
    
    
}