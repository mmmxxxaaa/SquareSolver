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

        bool error_flag = get_coeffs(&coeffs);
        /*
        float right_part;
        search_right_part(&right_part);
        coef_c -= right_part;
        */
        clear_input_stream();

        if (!error_flag)
        {
            float x1, x2;
            int amount_of_roots;
            enum possible_solution_cases solution_case = general_solution(&x1, &x2, &amount_of_roots, coeffs);

            general_output(x1, x2, amount_of_roots, solution_case);
        }
        if (continue_request() == -1)
            break;
    }
}

