#include "global_test.h"

#include <math.h>

#include "logic_functions_test.h"
#include "equation_solver_test.h"

#include "equation_solver.h"


void global_test(void)
{
    test_is_zero(0.4f, 0);
    test_is_zero(4e-12f, 1);

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

    test_solve_general_simplified(0, 0, 0,       0, 0, SOLUTION_TYPE_INF_ROOTS);

}
