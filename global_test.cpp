#include "global_test.h"

#include <math.h>

#include "logic_functions_test.h"
#include "equation_solver_test.h"

#include "equation_solver.h"

// ХУЙНЯ ПЕРЕДЕЛЫВАЙ (void)
void global_test(void)
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

// ХУЙНЯ ПЕРЕДЕЛЫВАЙ - побольше пжпжпжпжп
// Добавь структуру, содержащую две эти структуры типо struct Test и сделай один большой массив
    QuadricCoeffs many_tests_coeffs[] = {{0, 0, 0}, {0, 0, 1}};
    AnswerAndSolution many_tests_results[] = {{0, 0, SOLUTION_TYPE_INF_ROOTS}, {0, 0, SOLUTION_TYPE_NO_ROOTS}};
    int amount_of_tests = sizeof(many_tests_coeffs) / sizeof(many_tests_coeffs[0]);

    for (int i = 0; i < amount_of_tests - 1; i++)
        test_solve_general(many_tests_coeffs[i], many_tests_results[i]);
}
