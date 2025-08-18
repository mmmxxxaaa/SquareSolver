#include "processing.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool get_coeffs(struct QuadricCoeffs * ptr_coeffs)
{
    assert(ptr_coeffs != NULL);

    if (scanf("%f %f %f", &(ptr_coeffs->coef_a), &(ptr_coeffs->coef_b), &(ptr_coeffs->coef_c)) != 3)
    {
        puts(RED BOLD "Wrong input. Please, enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0\n" NORMAL RESET);
        return true;
    }
    else
        return false;
}

void general_output(struct AnswerAndSolution result)
{
    switch(result.solution_case)   //advisedly added everywhere one more \n to make output more readable
    {
        case inf_roots:
            puts(GREEN "Any x from [-INF; +INF] is the root of this equation\n" RESET);
            break;
        case no_roots:
            puts(GREEN "This equation doesn't have any root\n" RESET);
            break;
        case linear_has_1_root:
        {
            puts(GREEN "This is not an quadratic equation, but it is linear equation and it has one root:" RESET);
            printf(BGGREEN "x = %f" BGDEF "\n\n", result.x1);
            break;
        }
        case quadric_has_1_root:
        {
            printf(GREEN "This quadratic equation has %d root\n" RESET, result.amount_of_roots);
            printf(BGGREEN "x = %f" BGDEF "\n\n", result.x1);
            break;
        }
        case quadric_has_2_roots:
        {
            printf(GREEN "This quadratic equation has %d roots\n" RESET, result.amount_of_roots);
            printf(BGGREEN "x1 = %f     x2 = %f" BGDEF "\n\n", result.x1, result.x2);
            break;
        }
        case quadric_has_0_roots:
        {
            puts(GREEN "This quadratic equation does not have roots in real numbers\n" RESET);
            break;
        }
        default:
            break;


    }
}

void clear_input_stream()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}

int continue_request()
{
    puts(BLUE "Enter new quadratic quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0" RESET);
    puts(BLUE "Or enter 'q' to quit the program" RESET);

    int stop_ch = getchar();
    if (stop_ch != 'q')
    {
        ungetc(stop_ch, stdin);
        return 1;
    }
    else
        return -1;
}
