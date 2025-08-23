#include "equation_solver_test.h"

#include <stdio.h>

#include "equation_solver.h"
#include "logic_functions.h"

QuadricCoeffs coeffs {0, 0, 0};
AnswerAndSolution result {0, 0, SOLUTION_TYPE_NONE};

void make_coeffs(float coef_a, float coef_b, float coef_c, QuadricCoeffs* ptr_coeffs)
{
    ptr_coeffs->a = coef_a;
    ptr_coeffs->b = coef_b;
    ptr_coeffs->c = coef_c;
}

void test_normal_solve_general(QuadricCoeffs* ptr_coeffs, AnswerAndSolution* ptr_result, float expecting_x1, float expecting_x2, enum SolutionType expecting_case)
{
    enum SolutionType check_case = solve_general(ptr_coeffs, ptr_result);
    int flag = 1;
    if (!is_zero(ptr_result->x1 - expecting_x1))
        flag = 0;
    else if (!is_zero(ptr_result->x2 - expecting_x2))
        flag = 0;
    else if (check_case != expecting_case)
        flag = 0;
    if (!flag)
        printf("FAILED solve_general({%f, %f, %f}) -> {%f %f %d}  (should be {%f %f %d})",
            ptr_coeffs->a, ptr_coeffs->b, ptr_coeffs->c,
            ptr_result->x1, ptr_result->x2, ptr_result->solution_case,
            expecting_x1, expecting_x2, expecting_case);
}

void test_solve_general_simplified(float coef_a, float coef_b, float coef_c, float expecting_x1, float expecting_x2, enum SolutionType expecting_case)
{
    make_coeffs(coef_a, coef_b, coef_c, &coeffs);
    test_normal_solve_general(&coeffs, &result, expecting_x1, expecting_x2, expecting_case);
}
