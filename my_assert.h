#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_
// ХУЙНЯ ПЕРЕДЕЛЫВАЙ - добавь сообщение для вывода объяснения, на случай, если упадёт ассерт
#define MY_ASSERT(expression) my_assert_function(expression, #expression, __FILE__, __LINE__)

/**
    @brief Используется в макросе my_assert.

    @param[in] constant_expression Константное выражение, значение которого мы проверяем
    @param[in] ptr_name_of_file Указатель на название файла, в котором вызывается функция
    @param[in] number_of_line Номер строки, в которой вызывается функция

**/
void my_assert_function(int expression, const char* expression_string, const char* name_of_file, int number_of_line);

#endif // MY_ASSERT_H_
