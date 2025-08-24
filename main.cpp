#include <stdio.h>
#include <stdbool.h>

#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_static_assert.h"
#include "global_test.h"

#include "my_assert.h"

// FIXME argc argv
int main()
{
    global_test();

    //MY_ASSERT("Poltorashka" == "dog");
    //MY_ASSERT_WITH_MESSAGE(0 == 1, "переделывай");

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
            RootsAndCase result = {0};
            result.solution_case = solve_general(&coeffs, &result);

            output_general(result);
        }
        if (continue_request() == -1)
            break;
    }
}
