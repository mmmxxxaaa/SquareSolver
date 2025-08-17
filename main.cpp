#include <stdio.h>
#include <stdbool.h>

#include "processing.h"
#include "equation_solver.h"

int main()
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    while (stop_ch != 'q')
    {
        struct quadric_coeffs coeffs;

        bool is_failed = get_coeffs(&coeffs);
        /*
        float right_part;
        search_right_part(&right_part);
        coef_c -= right_part;
        */
        clear_input_stream();

        if (!is_failed)
        {
            struct answer_and_solution result;
            result.solution_case = general_solution(&result, coeffs);

            general_output(result);
        }
        if (continue_request() == -1)
            break;
    }
}

