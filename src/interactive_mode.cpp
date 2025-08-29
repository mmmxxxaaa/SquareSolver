#include "../include/interactive_mode.h"

#include <stdio.h>

#include "../include/my_static_assert.h"
#include "../include/io.h"
#include "../include/equation_solver.h"
#include "../include/colors_codes.h"
#include "../include/my_assert.h"

void interactive_mode()
{
    puts(BLUE "Enter the quadratic equation coefficients in the following format: \"a b c\", "
         "where ax^2 + bx + c = 0" RESET);
    for (;;)
    {
        my_static_assert(sizeof(float) == 4);
        QuadricCoeffs coeffs = {0};

        bool got_success = get_coeffs(&coeffs);

        clear_input_stream();

        if (got_success)
        {
            logger_output(LOGGER_PRIORITY_INFO, "successfully got coeffs\n");

            RootsAndCase result = {0, 0, SOLUTION_TYPE_NONE};

            result.solution_case = solve_general(&coeffs, &result);
            MY_ASSERT(result.solution_case != SOLUTION_TYPE_NONE);

            output_general(result);
            logger_output(LOGGER_PRIORITY_INFO, "Printed output\n");
        }
        else
            logger_output(LOGGER_PRIORITY_ERROR, "User made wrong input\n");
        if (continue_request() == -1)
        {
            logger_output(LOGGER_PRIORITY_INFO, "User exited the program\n");
            break;
        }
    }
}
