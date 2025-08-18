#include <stdio.h>
#include <stdbool.h>

#include "processing.h"
#include "equation_solver.h"

int main()
{
    char stop_ch = 'w';

    puts("\033[34m" "Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0" "\033[0m");
    while (stop_ch != 'q')
    {
        struct QuadricCoeffs coeffs;

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

