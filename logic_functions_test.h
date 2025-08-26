#ifndef LOGIC_FUNCTIONS_TEST_H_
#define LOGIC_FUNCTIONS_TEST_H_

/**
    @brief Функция тестирует работу функции is_zero
    @param[in] number - число, которое мы передадим функции is_zero
    @param[in] expecting_value - ожидамое значение, которая должна вернуть функция is_zero
*/
int test_is_zero(float number, bool expecting_value);

/**
    @brief Функция тестирует работу функции is_equal
    @param[in] number_1, number_2 - числа, которые мы передадим функции is_equal
    @param[in] expecting_value - ожидамое значение, которая должна вернуть функция is_equal
*/
int test_is_equal(float number_1, float number_2, bool expecting_value);

/**
    @brief Функция тестирует работу функции is_nan
    @param[in] number - число, которое мы передадим функции is_nan
    @param[in] expecting_value - ожидамое значение, которая должна вернуть функция is_nan
*/
int test_is_nan(float number, bool expecting_value);

/**
    @brief Функция тестирует работу функции is_inf
    @param[in] number - число, которое мы передадим функции is_inf
    @param[in] expecting_value - ожидамое значение, которая должна вернуть функция is_inf
*/
int test_is_inf(float number, bool expecting_value);

/**
    @brief Функция тестирует работу функции is_finite
    @param[in] number - число, которое мы передадим функции is_finite
    @param[in] expecting_value - ожидамое значение, которая должна вернуть функция is_nan
*/
int test_is_finite(float number, bool expecting_value);

#endif // LOGIC_FUNCTIONS_TEST_H_
