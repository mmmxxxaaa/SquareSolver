#include "logic_functions.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>


/**
    @brief Функция проверяет, является ли нулём значение числа типа float
    @param[in] number Число типа float, которое нужно сравнить с нулём
    @param[out] bool-значение проверки:
                1-число является нулём
                0-число не является нулём
**/
bool is_zero(float number)
{
    const float epsilon = 1e-7f;
    return fabsf(number) < epsilon;
}

/**
    @brief Функция проверяет, является ли NaN переданное ей число
    @param[in] number Число типа float, которое нужно проверить на NaN
    @param[out] bool-значение проверки:
                1-число имеет состояние NaN
                0-число имеет стандартное состояние
**/
bool is_nan(float number)
{
    return number != number;
}

/**
    @brief Функция проверяет, является ли INF переданное ей число
    @param[in] number Число типа float, которое нужно проверить на INF
    @param[out] bool-значение проверки:
                1-число имеет состояние INF
                0-число имеет стандартное состояние
**/
bool is_inf(float number)
{
    return number < -FLT_MAX || number > FLT_MAX;
}

/**
    @brief Функция проверяет, является ли переданное ей число стандартным (то есть не NaN и не INF)
    @param[in] number Число типа float, которое нужно проверить на NaN и INF
    @param[out] bool-значение проверки:
                1-число имеет стандартное состояние
                0-число имеет состояние Nan или INF
**/
bool is_finite(float number)
{
    return !is_inf(number) && !is_nan(number);
}
