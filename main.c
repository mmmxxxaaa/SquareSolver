#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*Remake
1. Functions prototypes are outside the main() now
2. a, b, c -> coef_a, coef_b, coef_c
3. pow(...) -> sqrt(...)
4. define -> const float
5. added is_zero() function
6. added search_right_part() function
7. added processing of zero coefficients
*/

const float epsilon = 1e-7; //using with fabs instead discriminant == 0

int is_zero(float number);
void clear_input_stream(void);

void get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
float make_discriminant(float coeff_a, float coeff_b, float coeff_c);
void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);
void search_right_part(float * ptr_right_part);  //Not necessary function yet


int main()
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0");
    while (stop_ch != 'q')
    {
        float coef_a, coef_b, coef_c, right_part;
        float discriminant;
        float x1, x2;


        get_coeffs(&coef_a, &coef_b, &coef_c);
        /*
        search_right_part(&right_part);
        coef_c -= right_part;
        */
        clear_input_stream();

        if (is_zero(coef_a) && is_zero(coef_b) && is_zero(coef_c))
            puts("This is not an equation and this mathematical expression is true, because 0 = 0\n");  //advisedly added \n to make output more readable
        else if (is_zero(coef_a) && is_zero(coef_b))
            printf("This is not an equation and this mathematical expression is false, becaude %f != 0\n\n", coef_c);  //advisedly added \n to make output more readable
        else if (is_zero(coef_a))
        {
            puts("This is not an quadratic equation, but it is linear equation and it has one root:");
            printf("x = %f\n", -coef_c/coef_b);
        }
        else
        {
            discriminant = make_discriminant(coef_a, coef_b, coef_c);

            if (discriminant < 0)
            {
                puts("This quadratic equation has no solutions in real numbers");
                printf("\n");
            }
            else if (is_zero(discriminant))
            {
                make_roots(&x1, &x2, coef_a, coef_b, fabs(discriminant));
                puts("The roots of this quadratic equation are repeated,");
                printf("so x1 = x2 = %f\n", x2);
                printf("\n");
            }
            else
            {
                make_roots(&x1, &x2, coef_a, coef_b, discriminant);
                puts("The roots of this quadratic equation are:");
                printf("x1 = %f    x2 = %f \n", x1, x2);
                printf("\n");
            }
        }

        //printf("coefs: %f %f %f \n", coef_a, coef_b, coef_c);    //debug
        //printf("discr: %f \n", discriminant);                    //debug
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
    if (fabs(number) < epsilon)
        return 1;
    else
        return 0;
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
    *ptr_x1 = ((-1) * coef_b + sqrt(discriminant)) / (2 * coef_a);
    *ptr_x2 = ((-1) * coef_b - sqrt(discriminant)) / (2 * coef_a);
}


void clear_input_stream(void)
{
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}
