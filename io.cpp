#include "io.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "colors_codes.h"
#include "my_assert.h"


bool get_coeffs(QuadricCoeffs* ptr_coeffs)
{
    MY_ASSERT(ptr_coeffs != NULL);
    if (scanf("%f %f %f", &(ptr_coeffs->a), &(ptr_coeffs->b), &(ptr_coeffs->c)) != 3)
    {
        puts(RED BOLD "Wrong input. Please, enter the quadratic equation coefficients in the "
            "following format: \"a b c\", where ax^2 +- bx +- c = 0\n" RESET RESET);
        return false;
    }
    else
        return true;
}

void output_general(RootsAndCase result)
{
    switch(result.solution_case)   //added everywhere one more \n to make output more readable
    {
        case SOLUTION_TYPE_INF_ROOTS:
            puts(GREEN "Any x from [-INF; +INF] is the root of this equation\n" RESET);
            break;
        case SOLUTION_TYPE_NO_ROOTS:
            puts(GREEN "This equation doesn't have any root\n" RESET);
            break;
        case SOLUTION_TYPE_LINEAR_HAS_1_ROOT:
        {
            puts(GREEN "This is linear equation and it has one root:" RESET);
            printf(BGGREEN "x = %f" BGDEF "\n\n", result.x1);
            break;
        }
        case SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT:
        {
            printf(GREEN "This quadratic equation has 1 root\n" RESET);
            printf(BGGREEN "x = %f" BGDEF "\n\n", result.x1);
            break;
        }
        case SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS:
        {
            printf(GREEN "This quadratic equation has 2 roots\n" RESET);
            printf(BGGREEN "x1 = %f     x2 = %f" BGDEF "\n\n", result.x1, result.x2);
            break;
        }
        case SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS:
        {
            puts(GREEN "This quadratic equation does not have roots in real numbers\n" RESET);
            break;
        }
        case SOLUTION_TYPE_NONE:
        {
            puts(RED "Error: solution case does not initialized" RESET);
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
    puts(BLUE "Enter new quadratic quadratic equation coefficients"
        " in the following format: \"a b c\", where ax^2 + bx + c = 0" RESET);
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


bool search_flag(const char* name_of_flag, const int amount_of_input, const char** input)
{
    for (int i = 0; i < amount_of_input; input++, i++)
        if (strcmp(name_of_flag, *input) == 0)
            return true;
    return false;
}
