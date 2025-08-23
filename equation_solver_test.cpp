#include "equation_solver_test.h"

#include <stdio.h>

#include "equation_solver.h"
#include "logic_functions.h"



void test_solve_general(QuadricCoeffs* ptr_coeffs, AnswerAndSolution* ptr_result, float expecting_x1, float expecting_x2, enum SolutionType expecting_case)
{
    solve_general(ptr_coeffs, ptr_result);
    int flag = 1;
    if (!is_zero(ptr_result->x1 - expecting_x1))
        flag = 0;
    else if (!is_zero(ptr_result->x2 - expecting_x2))
        flag = 0;
    else if (ptr_result->solution_case != expecting_case)
        flag = 0;
    if (!flag)
        printf("FAILED solve_general({%f, %f, %f}) -> {%f %f %d}  (should be {%f %f %d})",
            ptr_coeffs->a, ptr_coeffs->b, ptr_coeffs->c,
            ptr_result->x1, ptr_result->x2, ptr_result->solution_case,
            expecting_x1, expecting_x2, expecting_case);


}
