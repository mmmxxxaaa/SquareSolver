#include "logic_functions_test.h"

#include <stdio.h>
#include <stdbool.h>

#include "logic_functions.h"

void test_is_zero(float number, bool expecting_value)
{
    bool check = is_zero(number);
    if (check != expecting_value)
        printf("FAILED: is_zero(number) -> %d (should be %d)\n", check, expecting_value);
}

void test_is_nan(float number, bool expecting_value)
{
    bool check = is_nan(number);
    if (check != expecting_value)
        printf("FAILED is_nan(number) -> %d (should be %d)\n", check, expecting_value);
}

void test_is_inf(float number, bool expecting_value)
{
    bool check = is_inf(number);
    if (check != expecting_value)
        printf("FAILED is_inf(number) -> %d (should be %d)\n", check, expecting_value);
}

void test_is_finite(float number, bool expecting_value)
{
    bool check = is_finite(number);
    if (check != expecting_value)
        printf("FAILED is_finite(%f) -> %d (should be %d)\n", number, check, expecting_value);
}
