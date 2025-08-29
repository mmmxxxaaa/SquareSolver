#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#define MY_ASSERT(expression) my_assert_function(expression, #expression, __FILE__, __LINE__)

#define MY_ASSERT_WITH_MESSAGE(expression, message) \
my_assert_with_message_function(expression, #expression, __FILE__, __LINE__, message)

/**
    @brief Используется в макросе my_assert.

    @param[in] expression Константное выражение, значение которого мы проверяем
    @param[in] expression_string Содержание проверки
        (символьное представление строки expression без расчётов)
    @param[in] name_of_file Указатель на название файла, в котором вызывается функция
    @param[in] number_of_line Номер строки, в которой вызывается функция

**/
void my_assert_function(int expression, const char* expression_string, const char* name_of_file,
    int number_of_line);

/**
    @brief Используется в макросе my_assert_with_message.

    @param[in] expression Константное выражение, значение которого мы проверяем
    @param[in] expression_string Содержание проверки
               (символьное представление строки expression без расчётов)
    @param[in] name_of_file Указатель на название файла, в котором вызывается функция
    @param[in] number_of_line Номер строки, в которой вызывается функция
    @param[in] message Сообщение, выводимое при ложном результате проверки выражения expression

**/
void my_assert_with_message_function(int expression, const char* expression_string,
    const char* name_of_file, int number_of_line, const char* message);

#endif // MY_ASSERT_H_
