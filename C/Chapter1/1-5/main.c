#include "compress_str.h"
#include "print_array.h"

int main()
{
    char test[] = "Hello";
    char* out = NULL;

    print_char_array(test, strlen(test));
    compress_str(test, &out);
    print_char_array(out, strlen(out));

}