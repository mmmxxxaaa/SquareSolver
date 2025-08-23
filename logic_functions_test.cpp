#include "logic_functions_test.h"

#include <stdio.h>

#include "logic_functions.h"

void test_is_zero_1()
{
    float number = 0.4f;
    int check = is_zero(number);
    if (check)
        printf("FAILED: is_zero(0.4) -> 1 (should be 0)\n");
}

void test_is_zero_2()
{
    float number = 4e-12f;
    int check = is_zero(number);
    if (!check)
        printf("FAILED: is_zero(4e-12) -> 0 (should be 1)\n");
}
