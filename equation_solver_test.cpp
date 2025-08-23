#include "equation_solver_test.h"

#include <stdio.h>

#include "equation_solver.h"

void test_solve_general_1(void)
{
    QuadricCoeffs coeffs1 = {0, 0, 0};
    AnswerAndSolution result1 = {0, 0, SOLUTION_TYPE_NONE};

    solve_general(&coeffs1, &result1);

    if (!result1.solution_case == SOLUTION_TYPE_INF_ROOTS)
        printf("FAILED solve_general({0, 0, 0}, {0, 0, SOLUTION_TYPE_NONE) got NOT A 'SOLUTION_TYPE_INF_ROOTS' ");

}
