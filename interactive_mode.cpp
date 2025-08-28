#include "interactive_mode.h"

#include <stdio.h>

#include "my_static_assert.h"
#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_assert.h"

void interactive_mode(enum LoggerPriority logger_type)
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
            logger_output("successfully got coeffs\n", LOGGER_PRIORITY_INFO, logger_type);

            RootsAndCase result = {0, 0, SOLUTION_TYPE_NONE};

            result.solution_case = solve_general(&coeffs, &result, logger_type);
            MY_ASSERT(result.solution_case != SOLUTION_TYPE_NONE);

            output_general(result);
            logger_output("Printed output\n", LOGGER_PRIORITY_INFO, logger_type);
        }
        else
            logger_output("User made wrong input\n", LOGGER_PRIORITY_ERROR, logger_type);
        if (continue_request() == -1)
        {
            logger_output("User exited the program\n", LOGGER_PRIORITY_INFO, logger_type);
            break;
        }
    }
}
