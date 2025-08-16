#include <stdio.h>
#include <stdbool.h>
 #include <assert.h>

#include "processing.h"

bool get_coeffs(float * ptr_a, float * ptr_b, float * ptr_c)
{
    assert(ptr_a != NULL);
    assert(ptr_b != NULL);
    assert(ptr_c != NULL);

    if (scanf("%f %f %f", ptr_a, ptr_b, ptr_c) != 3)
    {
        puts("Wrong input. Please, enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0\n");
        return true;
    }
    else
        return false;
}

void search_right_part(float * ptr_right_part)    //Not necessary function yet
{
    int ch;

    assert(ptr_right_part);

    while ((ch = getchar()) != '\n' && ch != EOF)
        if (ch == '=')
        {
            scanf("%f", ptr_right_part);
            break;
        }
}

void general_output(float x1, float x2, int amount_of_roots, enum possible_solution_cases solution_case)
{
    switch(solution_case)   //advisedly added everywhere one more \n to make output more readable
    {
        case inf_roots:
            puts("Any x from [-INF; +INF] is the root of this equation\n");
            break;
        case no_roots:
            puts("This equation doesn't have any root\n");
            break;
        case linear_has_1_root:
        {
            puts("This is not an quadratic equation, but it is linear equation and it has one root:");
            printf("x = %f\n\n", x1);
            break;
        }
        case quadric_has_1_root:
        {
            printf("This quadratic equation has %d root\n", amount_of_roots);
            printf("x = %f\n\n", x1);
            break;
        }
        case quadric_has_2_roots:
        {
            printf("This quadratic equation has %d roots\n", amount_of_roots);
            printf("x1 = %f     x2 = %f\n\n", x1, x2);
            break;
        }
        case quadric_has_0_roots:
        {
            puts("This quadratic equation does not have roots in real numbers\n");
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
    int stop_ch;

    puts("Enter new quadratic quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    puts("Or enter 'q' to quit the program");
    stop_ch = getchar();
    if (stop_ch != 'q')
    {
        ungetc(stop_ch, stdin);
        return 1;
    }
    else
        return -1;
}
