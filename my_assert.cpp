#include <stdio.h>
#include <stdlib.h>

#include "my_assert.h"

void my_assert_function(int constant_expression, const char* name_of_file, int number_of_line)
{
    if (!constant_expression)
    {
        fprintf(stderr, "Error in %s file on the %d line\n", name_of_file, number_of_line);
        abort();
    }
}
