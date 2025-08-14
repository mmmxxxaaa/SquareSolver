#include "functions.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool get_coeffs(float * ptr_a, float * ptr_b, float * ptr_c)
{
    if (scanf("%f %f %f", ptr_a, ptr_b, ptr_c) != 3)
    {
        puts("Wrong input. Please, enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0\n");
        return true;
    }
    else
        return false;
}

float make_discriminant(float coef_a, float coef_b, float coef_c)
{
    return coef_b * coef_b - 4 * coef_a * coef_c;
}

void make_roots(float *ptr_x1, float *ptr_x2, float coef_a, float coef_b, float discriminant)
{
    float discr_square_root = sqrt(discriminant);

    *ptr_x1 = ((-1) * coef_b + discr_square_root) / (2 * coef_a);
    *ptr_x2 = ((-1) * coef_b - discr_square_root) / (2 * coef_a);
}

void search_right_part(float * ptr_right_part)    //Not necessary function yet
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        if (ch == '=')
        {
            scanf("%f", ptr_right_part);
            break;
        }
}


enum possible_solution_cases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coef_b, float coef_c)
{
    *ptr_x1 = *ptr_x2 = -coef_c/coef_b;
    *ptr_amount_of_roots = 1;
    return only_a_coef_0;
}

enum possible_solution_cases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coef_a, float coef_b, float coef_c)
{
    float discriminant = make_discriminant(coef_a, coef_b, coef_c);

    if (discriminant < 0)
    {
        *ptr_amount_of_roots = 0;
        return quadric_has_0_roots;
    }
    else if (is_zero(discriminant))
    {
        make_roots(ptr_x1, ptr_x2, coef_a, coef_b, fabs(discriminant));
        *ptr_amount_of_roots = 1;
        return quadric_has_1_root;
    }
    else
    {
        make_roots(ptr_x1, ptr_x2, coef_a, coef_b, discriminant);
        *ptr_amount_of_roots = 2;
        return quadric_has_2_roots;
    }
}

enum possible_solution_cases general_solution(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coef_a, float coef_b, float coef_c)
{
    if (is_zero(coef_a) && is_zero(coef_b) && is_zero(coef_c))
        return all_abc_coef_0;
    else if (is_zero(coef_a) && is_zero(coef_b))
        return only_ab_coef_0;
    else if (is_zero(coef_a))
        return solve_normal_linear_equation(ptr_x1, ptr_x2, ptr_amount_of_roots, coef_b, coef_c);
    else
        return solve_normal_quadratic_equation(ptr_x1, ptr_x2, ptr_amount_of_roots, coef_a, coef_b, coef_c);
}

void general_output(float x1, float x2, int amount_of_roots, enum possible_solution_cases solution_case)
{
    switch(solution_case)   //advisedly added everywhere one more \n to make output more readable
    {
        case all_abc_coef_0:
            puts("Any x from [-INF; +INF] is the root of this equation\n");
            break;
        case only_ab_coef_0:
            puts("This equation doesn't have any root\n");
            break;
        case only_a_coef_0:
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

bool is_zero(float number)
{
    const double epsilon = 1e-7;
    return fabs(number) < epsilon;
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
