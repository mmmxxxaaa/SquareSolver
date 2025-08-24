#include "global_test.h"

#include <math.h>

#include "logic_functions_test.h"
#include "equation_solver_test.h"

#include "equation_solver.h"

void global_test()
{
    test_is_zero(0.4f, 0);
    test_is_zero(4e-12f, 1);

    test_is_equal(0, 0, 1);
    test_is_equal(0.001f, 0.0001f, 0);

    test_is_nan(0.451387f, 0);
    test_is_nan(NAN, 1);

    test_is_inf(1e20f, 0);
    test_is_inf(0, 0);
    test_is_inf(-1e20f, 0);
    test_is_inf(INFINITY, 1);

    test_is_finite(1e20f, 1);
    test_is_finite(-1e20f, 1);
    test_is_finite(0, 1);
    test_is_finite(NAN, 0);
    test_is_finite(INFINITY, 0);

    Test many_tests[] = {
        {{0,  0, 0}, { 0,  0, SOLUTION_TYPE_INF_ROOTS            }},
        {{0,  0, 1}, { 0,  0, SOLUTION_TYPE_NO_ROOTS             }},
        {{0,  1, 0}, { 0,  0, SOLUTION_TYPE_LINEAR_HAS_1_ROOT    }},
        {{1,  0, 0}, { 0,  0, SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT }},
        {{1,  2, 1}, {-1, -1, SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT }},
        {{1, -5, 6}, { 3,  2, SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS}}
    };

    int amount_of_tests = sizeof(many_tests) / sizeof(many_tests[0]);

    for (int i = 0; i < amount_of_tests; i++)
        test_solve_general(many_tests[i].tests_coeffs, many_tests[i].tests_results);
}
