#include <stdio.h>
#include <stdbool.h>

#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_static_assert.h"
#include "global_test.h"

#include "my_assert.h"

// TODO -

int main()
{
    global_test();

    //MY_ASSERT("Poltorashka" == "dog");

    puts(BLUE "Enter the quadratic equation coefficients in the following format: \"a b c\", "
         "where ax^2 + bx + c = 0" RESET);
    for (;;)
    {
        my_static_assert(sizeof(float) == 4);
        QuadricCoeffs coeffs = {0};

        bool is_failed = get_coeffs(&coeffs);
        clear_input_stream();

        if (!is_failed)
        {
            AnswerAndSolution result = {0};
            result.solution_case = solve_general(&coeffs, &result);

            output_general(result);
        }
        if (continue_request() == -1)
            break;
    }
}
