#include "processing.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool get_coeffs(struct QuadricCoeffs * ptr_coeffs)
{
    assert(ptr_coeffs != NULL);

    if (scanf("%f %f %f", &(ptr_coeffs->coef_a), &(ptr_coeffs->coef_b), &(ptr_coeffs->coef_c)) != 3)
    {
        puts("\033[31mWrong input. Please, enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0\n\033[0m");
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
            puts("\033[32mAny x from [-INF; +INF] is the root of this equation\n\033[0m");
            break;
        case no_roots:
            puts("\033[32mThis equation doesn't have any root\n\033[0m");
            break;
        case linear_has_1_root:
        {
            puts("\033[32mThis is not an quadratic equation, but it is linear equation and it has one root:\033[0m");
            printf("x = %f\n\n", result.x1);
            break;
        }
        case quadric_has_1_root:
        {
            printf("\033[32mThis quadratic equation has %d root\n\033[0m", result.amount_of_roots);
            printf("x = %f\n\n", result.x1);
            break;
        }
        case quadric_has_2_roots:
        {
            printf("\033[32mThis quadratic equation has %d roots\n\033[0m", result.amount_of_roots);
            printf("x1 = %f     x2 = %f\n\n", result.x1, result.x2);
            break;
        }
        case quadric_has_0_roots:
        {
            puts("\033[32mThis quadratic equation does not have roots in real numbers\n\033[0m");
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
    puts("\033[34mEnter new quadratic quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0\033[0m");
    puts("\033[34mOr enter 'q' to quit the program\033[0m");

    int stop_ch = getchar();
    if (stop_ch != 'q')
    {
        ungetc(stop_ch, stdin);
        return 1;
    }
    else
        return -1;
}
