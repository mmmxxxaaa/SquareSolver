#include "../include/global_test.h"

#include <math.h>
#include <stdio.h>

#include "../include/logic_functions_test.h"
#include "../include/equation_solver_test.h"
#include "../include/colors_codes.h"

#include "../include/equation_solver.h"
#include "../include/logger.h"

void global_test()
{
    int success_tests = 0;
    int all_tests = 0;

    success_tests += test_is_zero(0.4f, 0); //1
    all_tests += 1;

    success_tests += test_is_zero(4e-12f, 1); //2
    all_tests += 1;

    logger_output(LOGGER_PRIORITY_INFO, "global_test(): tests test_is_zero passed\n");

    success_tests += test_is_equal(0, 0, 1); //3
    all_tests += 1;

    success_tests += test_is_equal(0.001f, 0.0001f, 0); //4
    all_tests += 1;

    logger_output(LOGGER_PRIORITY_INFO, "global_test(): tests test_is_equal passed\n");

    success_tests += test_is_nan(0.451387f, 0); //5
    all_tests += 1;

    success_tests += test_is_nan(NAN, 1); //6
    all_tests += 1;

    logger_output(LOGGER_PRIORITY_INFO, "global_test(): tests test_is_nan passed\n");

    success_tests += test_is_inf(1e20f, 0); //7
    all_tests += 1;

    success_tests += test_is_inf(0, 0); //8
    all_tests += 1;

    success_tests += test_is_inf(-1e20f, 0); //9
    all_tests += 1;
    success_tests += test_is_inf(INFINITY, 1); //10
    all_tests += 1;

    logger_output(LOGGER_PRIORITY_INFO, "global_test(): tests test_is_inf passed\n");

    success_tests += test_is_finite(1e20f, 1); //11
    all_tests += 1;
    success_tests += test_is_finite(-1e20f, 1); //12
    all_tests += 1;
    success_tests += test_is_finite(0, 1); //13
    all_tests += 1;
    success_tests += test_is_finite(NAN, 0); //14
    all_tests += 1;
    success_tests += test_is_finite(INFINITY, 0); //15
    all_tests += 1;

    logger_output(LOGGER_PRIORITY_INFO, "global_test(): tests test_is_finite passed\n");

    /***
    Test many_tests[] = {
        {{0,  0, 0}, { 0,  0, SOLUTION_TYPE_INF_ROOTS            }},
        {{0,  0, 1}, { 0,  0, SOLUTION_TYPE_NO_ROOTS             }},
        {{0,  1, 0}, { 0,  0, SOLUTION_TYPE_LINEAR_HAS_1_ROOT    }},
        {{1,  0, 0}, { 0,  0, SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT }},
        {{1,  2, 1}, {-1, -1, SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT }},
        {{1, -5, 6}, { 3,  2, SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS}}
    };

    ***/

    int opened = run_tests_from_file(&success_tests, &all_tests);
    if (!opened)
    {
        printf(RED BOLD "Failed opening the file with test \n" RESET);
        logger_output(LOGGER_PRIORITY_ERROR, "Failed opening the file with test \n");
    }

    /***
    int amount_of_tests = sizeof(many_tests) / sizeof(many_tests[0]);

    for (int i = 0; i < amount_of_tests; i++)
    {
        success_tests += test_solve_general(many_tests[i].tests_coeffs, many_tests[i].tests_results);
        all_tests += 1;
    }
    ***/
    printf(GREEN BOLD "%d of %d tests passed\n" RESET, success_tests, all_tests);
    if (success_tests == all_tests)
    {
        printf(GREEN BOLD "All tests passed successfully\n" RESET);
        logger_output(LOGGER_PRIORITY_INFO, "All tests passed successfully\n");
    }
}


int run_tests_from_file(int* success_tests, int* all_tests)
{
    FILE *file = fopen("./tests/tests.txt", "r");

    if (file == NULL)
    {
        logger_output(LOGGER_PRIORITY_CRITICAL, "run_tests_from_file(): Cannot open the file\n");
        return 0;
    }

    while (!feof(file))
    {
        QuadricCoeffs coeffs = {};
        RootsAndCase expected_roots {0 , 0, SOLUTION_TYPE_NONE};
        int tmp_int_to_enum = 0;

        int count_coeffs = fscanf(file, "%f %f %f", &coeffs.a, &coeffs.b, &coeffs.c);
        int count_expected_roots = fscanf(file, "%f %f %d", &expected_roots.x1, &expected_roots.x2,
            &tmp_int_to_enum);
        expected_roots.solution_case = (SolutionType) tmp_int_to_enum;
        if ((count_coeffs + count_expected_roots) != 6)
            break;
        *success_tests += test_solve_general(coeffs, expected_roots);
        *all_tests = *all_tests + 1;
    }


    fclose(file);
    logger_output(LOGGER_PRIORITY_DEBUG, "run_tests_from_file(): File with tests was closed\n");


    return 1;
}

