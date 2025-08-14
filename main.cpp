#include "functions.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


/*Changes
1. Split program into 3 files
*/

int main()
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    while (stop_ch != 'q')
    {
        float coef_a, coef_b, coef_c;
        bool error_flag = get_coeffs(&coef_a, &coef_b, &coef_c);
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
            enum possible_solution_cases solution_case = general_solution(&x1, &x2, &amount_of_roots, coef_a, coef_b, coef_c);

            general_output(x1, x2, amount_of_roots, solution_case);
        }
        if (continue_request() == -1)
            break;
    }
}

