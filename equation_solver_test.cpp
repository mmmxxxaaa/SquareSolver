#include "equation_solver_test.h"

#include <stdio.h>

#include "equation_solver.h"
#include "logic_functions.h"
#include "my_assert.h"
#include "colors_codes.h"

int test_solve_general(QuadricCoeffs coeffs, RootsAndCase expected_result)
{
    MY_ASSERT(is_finite(coeffs.a));
    MY_ASSERT(is_finite(coeffs.b));
    MY_ASSERT(is_finite(coeffs.c));

    RootsAndCase calculated_result;
    enum SolutionType check_case = solve_general(&coeffs, &calculated_result);

    int flag = 1;
    if (!is_equal(calculated_result.x1, expected_result.x1))
        flag = 0;
    else if (!is_equal(calculated_result.x2, expected_result.x2))
        flag = 0;
    else if (check_case != expected_result.solution_case)
        flag = 0;

    if (!flag)
    {
        printf(RED BOLD "FAILED solve_general({%f, %f, %f}) -> {%f %f %d} (should be {%f %f %d})\n"
            RESET, coeffs.a, coeffs.b, coeffs.c,
            calculated_result.x1, calculated_result.x2, check_case,
            expected_result.x1, expected_result.x2, expected_result.solution_case);
        return 0;
    }
    return 1;
}
