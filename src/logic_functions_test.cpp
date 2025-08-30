#include "logic_functions_test.h"

#include <stdio.h>
#include <stdbool.h>

#include "logic_functions.h"

int test_is_zero(float number, bool expecting_value)
{
    bool check = is_zero(number);
    if (check != expecting_value)
    {
        printf("FAILED: is_zero(%f) -> %d (should be %d)\n", number ,check, expecting_value);
        return 0;
    }
    return 1;
}

int test_is_equal(float number_1, float number_2, bool expecting_value)
{
    bool check = is_equal(number_1, number_2);
    if (check != expecting_value)
    {
        printf("FAILED: is_equal(%f, %f) -> %d (should be %d)\n",
            number_1, number_2, check, expecting_value);
        return 0;
    }
    return 1;
}

int test_is_nan(float number, bool expecting_value)
{
    bool check = is_nan(number);
    if (check != expecting_value)
    {
        printf("FAILED is_nan(%f) -> %d (should be %d)\n", number ,check, expecting_value);
        return 0;
    }
    return 1;
}

int test_is_inf(float number, bool expecting_value)
{
    bool check = is_inf(number);
    if (check != expecting_value)
    {
        printf("FAILED is_inf(%f) -> %d (should be %d)\n", number, check, expecting_value);
        return 0;
    }
    return 1;
}

int test_is_finite(float number, bool expecting_value)
{
    bool check = is_finite(number);
    if (check != expecting_value)
    {
        printf("FAILED is_finite(%f) -> %d (should be %d)\n", number, check, expecting_value);
        return 0;
    }
    return 1;
}
