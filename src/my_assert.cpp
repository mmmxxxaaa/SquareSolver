#include "my_assert.h"

#include <stdio.h>
#include <stdlib.h>

#include "colors_codes.h"

void my_assert_function(int expression, const char* expression_string, const char* ptr_name_of_file,
    int number_of_line)
{
    if (!expression)
    {
        fprintf(stderr, BOLD "%s:%d" RESET RED BOLD " assertion:" RESET RESET " %s failed\n",
            ptr_name_of_file, number_of_line, expression_string);
        abort();
    }
}

void my_assert_with_message_function(int expression, const char* expression_string,
    const char* ptr_name_of_file, int number_of_line, const char* message)
{
    if (!expression)
    {
        fprintf(stderr, BOLD "%s:%d" RESET RED BOLD " assertion:" RESET RESET
            " %s failed with message: %s\n", ptr_name_of_file,
            number_of_line, expression_string, message);
        abort();
    }
}

