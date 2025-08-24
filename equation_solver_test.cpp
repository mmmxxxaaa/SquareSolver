#include "equation_solver_test.h"

#include <stdio.h>

#include "equation_solver.h"
#include "logic_functions.h"
// ХУЙНЯ ПЕРЕДЕЛЫВАЙ - ideal or expected?
void test_solve_general(QuadricCoeffs coeffs, AnswerAndSolution ideal_result)
{
// ХУЙНЯ ПЕРЕДЕЛЫВАЙ net assert na float
    AnswerAndSolution calculated_result;
    enum SolutionType check_case = solve_general(&coeffs, &calculated_result);
    int flag = 1;
    if (!is_equal(calculated_result.x1, ideal_result.x1))
        flag = 0;
    else if (!is_equal(calculated_result.x2, ideal_result.x2))
        flag = 0;
    else if (check_case != ideal_result.solution_case)
        flag = 0;
    if (!flag)
        printf("FAILED solve_general({%f, %f, %f}) -> {%f %f %d}  (should be {%f %f %d})",
            coeffs.a, coeffs.b, coeffs.c,
            calculated_result.x1, calculated_result.x2, check_case,
            ideal_result.x1, ideal_result.x2, ideal_result.solution_case);
}
