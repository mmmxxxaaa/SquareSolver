#include <stdio.h>
#include <stdlib.h>

#include "my_assert.h"

/**
    @brief Используется в макросе my_assert.

    @param[in] constant_expression Константное выражение, значение которого мы проверяем
    @param[in] ptr_name_of_file Указатель на название файла, в котором вызывается функция
    @param[in] number_of_line Номер строки, в которой вызывается функция

**/
void my_assert_function(int constant_expression, const char* ptr_name_of_file, int number_of_line)
{
    if (!constant_expression)
    {
        fprintf(stderr, "Error in %s file on the %d line\n", ptr_name_of_file, number_of_line);
        abort();
    }
}
