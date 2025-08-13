#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*Changes
1. simplified is_zero() + const float epsilon removed into is_zero
2. corrected my mathematical mistake in a = 0 b = 0 c = 0 case
3. added function solve_normal_quadratic_equation()
4. simplified make_roots()
5. changed the places of variable declarations
*/

int is_zero(float number);
void clear_input_stream(void);

void get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
float make_discriminant(float coeff_a, float coeff_b, float coeff_c);
void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);
void search_right_part(float * ptr_right_part);  //Not necessary function yet
int solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, float coeff_a, float coeff_b, float coeff_c);


int main()
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    while (stop_ch != 'q')
    {
        float coef_a, coef_b, coef_c, right_part;

        get_coeffs(&coef_a, &coef_b, &coef_c);
        /*
        search_right_part(&right_part);
        coef_c -= right_part;
        */
        clear_input_stream();

        if (is_zero(coef_a) && is_zero(coef_b) && is_zero(coef_c))
            puts("Any x from [-INF; +INF] is the root of this equation\n");  //advisedly added \n to make output more readable
        else if (is_zero(coef_a) && is_zero(coef_b))
            printf("This is not an equation and this mathematical expression is false, becaude %f != 0\n\n", coef_c);  //advisedly added \n to make output more readable
        else if (is_zero(coef_a))
        {
            puts("This is not an quadratic equation, but it is linear equation and it has one root:");
            printf("x = %f\n", -coef_c/coef_b);
        }
        else
        {
            int amount_of_roots;
            float x1, x2;

            amount_of_roots = solve_normal_quadratic_equation(&x1, &x2, coef_a, coef_b, coef_c);
            printf("This quadratic equation has %d root(s)\n", amount_of_roots);
            if (amount_of_roots == 1)
                printf("x = %f\n\n", x2);
            else if (amount_of_roots == 2)
                printf("x1 = %f    x2 = %f \n\n", x1, x2);
        }

        puts("Enter new quadratic quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
        puts("Or enter 'q' to quit the program");
        stop_ch = getchar();
        if (stop_ch != 'q')
            ungetc(stop_ch, stdin);
        else
            break;
    }
}

int is_zero(float number)
{
    const float epsilon = 1e-7;
    return fabs(number) < epsilon;
}


void get_coeffs(float * ptr_a, float * ptr_b, float * ptr_c)
{
    scanf("%f %f %f", ptr_a, ptr_b, ptr_c);

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

void clear_input_stream()
{
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}
