#include <stdio.h>
#include <stdbool.h>

#include "processing.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_static_assert.h"

int main()
{
    char stop_ch = 'w';

    puts(BLUE "Enter the quadratic equation coefficients in the following format: \"a b c\", "
         "where ax^2 +- bx +- c = 0" RESET);
    while (stop_ch != 'q')
    {
        struct QuadricCoeffs coeffs;

        my_static_assert(sizeof(float) == 4);
        bool is_failed = get_coeffs(&coeffs);
        clear_input_stream();

        if (!is_failed)
        {
            struct AnswerAndSolution result;
            result.solution_case = general_solution(&result, coeffs);

            general_output(result);
        }
        if (continue_request() == -1)
            break;
    }
}

