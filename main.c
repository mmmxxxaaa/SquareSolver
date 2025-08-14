#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*Changes
1. wrote correct type for solution_case
*/

enum possible_solution_cases {all_abc_coef_0,
                              only_ab_coef_0,
                              only_a_coef_0,
                              discriminant_equal_to_0,
                              discriminant_more_than_0,
                              discriminant_less_than_0};

void get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
float make_discriminant(float coeff_a, float coeff_b, float coeff_c);
void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);
void search_right_part(float * ptr_right_part);  //Not necessary function yet
int solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, float coeff_a, float coeff_b, float coeff_c);

int general_solution(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_a, float coeff_b, float coeff_c);  // mb add right_part later
void general_output(float x1, float x2, int amount_of_roots, enum possible_solution_cases solution_case);

int is_zero(float number);
void clear_input_stream(void);
int continue_request();

int main()
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    while (stop_ch != 'q')
    {
        float coef_a, coef_b, coef_c;


        get_coeffs(&coef_a, &coef_b, &coef_c);
        /*
        float right_part;
        search_right_part(&right_part);
        coef_c -= right_part;
        */
        clear_input_stream();

        float x1, x2;
        int amount_of_roots;
        enum possible_solution_cases solution_case = general_solution(&x1, &x2, &amount_of_roots, coef_a, coef_b, coef_c);

        general_output(x1, x2, amount_of_roots, solution_case);
        if (continue_request() == -1)
            break;
    }
}

void get_coeffs(float * ptr_a, float * ptr_b, float * ptr_c)
{
    scanf("%f %f %f", ptr_a, ptr_b, ptr_c);

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
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        if (ch == '=')
        {
            scanf("%f", ptr_right_part);
            break;
        }
}

int solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, float coef_a, float coef_b, float coef_c)
{
    float discriminant = make_discriminant(coef_a, coef_b, coef_c);

    if (discriminant < 0)
        return 0;
    else if (is_zero(discriminant))
    {
        make_roots(ptr_x1, ptr_x2, coef_a, coef_b, fabs(discriminant));
        return 1;
    }
    else
    {
        make_roots(ptr_x1, ptr_x2, coef_a, coef_b, discriminant);
        return 2;
    }
}

int general_solution(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coef_a, float coef_b, float coef_c)
{
    if (is_zero(coef_a) && is_zero(coef_b) && is_zero(coef_c))
        return all_abc_coef_0;
    else if (is_zero(coef_a) && is_zero(coef_b))
        return only_ab_coef_0;
    else if (is_zero(coef_a))
    {
        *ptr_x1 = *ptr_x2 = -coef_c/coef_b;
        return only_a_coef_0;
    }
    else
    {
        *ptr_amount_of_roots = solve_normal_quadratic_equation(ptr_x1, ptr_x2, coef_a, coef_b, coef_c);
        if (*ptr_amount_of_roots == 1)    //discriminant = 0
            return discriminant_equal_to_0;
        else if (*ptr_amount_of_roots == 2)  //discriminant > 0
            return discriminant_more_than_0;
        else
            return discriminant_less_than_0;   //discriminant < 0
    }
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
        case discriminant_equal_to_0:
        {
            printf("This quadratic equation has %d root\n", amount_of_roots);
            printf("x = %f\n\n", x1);
            break;
        }
        case discriminant_more_than_0:
        {
            printf("This quadratic equation has %d roots\n", amount_of_roots);
            printf("x1 = %f     x2 = %f\n\n", x1, x2);
            break;
        }
        case discriminant_less_than_0:
        {
            puts("This quadratic equation does not have roots in real numbers\n");
            break;
        }


    }
}

int is_zero(float number)
{
    const float epsilon = 1e-7;
    return fabs(number) < epsilon;
}

void clear_input_stream()
{
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}

int continue_request()
{
    char stop_ch;

    puts("Enter new quadratic quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    puts("Or enter 'q' to quit the program");
    stop_ch = getchar();
    if (stop_ch != 'q')
        ungetc(stop_ch, stdin);
    else
        return -1;
}
