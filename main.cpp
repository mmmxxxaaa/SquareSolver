#include <stdio.h>
#include <stdbool.h>

#include "processing.h"
#include "equation_solver.h"
//тут же не нужно include "logic_functions.h"? Или в мэйне всегда должны быть включены имеющиеся заголовочные файлы?

int main()
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    while (stop_ch != 'q')
    {
        struct {   // можно же без дескриптора? Она всего один раз встречается
            float coef_a;
            float coef_b;
            float coef_c;
        } coefficients;

        bool error_flag = get_coeffs(&coefficients.coef_a, &coefficients.coef_b, &coefficients.coef_c);
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
            enum possible_solution_cases solution_case = general_solution(&x1, &x2, &amount_of_roots, coefficients.coef_a, coefficients.coef_b, coefficients.coef_c);

            general_output(x1, x2, amount_of_roots, solution_case);
        }
        if (continue_request() == -1)
            break;
    }
}

