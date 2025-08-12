#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define EPSILON 1e-7 //using with fabs instead discriminant == 0



/*Questions:
!!! 1. How to make comments in Russian display correctly on github?  !!!
    2. How should input/output be released? (console/files)
    3. How to print +- symbol as one symbol
*/

/*Plans:
1. Make the entry "x^2" be interpreted as a = 1 instead of a = 0 and "x" as b = 1 instead of b = 0
2. Add zero coefficient recognition
3. Do user error handling
*/

int main(void)
{
    void get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
    float make_discriminant(float a, float b, float c);
    void make_roots(float *ptr_x1, float *ptr_x2, float a, float b, float discriminant);
    void clear_input_stream(void);

    char stop_ch = 'w';

    puts("Enter the quadratic equation in the following format: ax^2 +- bx +- c = k");
    while (stop_ch != 'q')
    {
        float a, b, c, right_part;
        float discriminant;
        float x1, x2;
        char ch;


        get_coeffs(&a, &b, &c);
        while ((ch = getchar()) != '\n' && ch != EOF)  //searching for right_part
            if (ch == '=')
            {
                scanf("%f", &right_part);
                break;
            }
        c -= right_part;
        clear_input_stream();



        discriminant = make_discriminant(a, b, c);

        if (discriminant < 0)
        {
            puts("This quadratic equation has no solutions in real numbers");
            printf("\n");
        }
        else if (fabs(discriminant) < EPSILON)
        {
            make_roots(&x1, &x2, a, b, fabs(discriminant));
            puts("The roots of this equation are repeated,");
            printf("so x1 = x2 = %f\n", x2);
            printf("\n");
        }
        else
        {
            make_roots(&x1, &x2, a, b, discriminant);
            puts("The roots of this equation are:");
            printf("x1 = %f    x2 = %f \n", x1, x2);
            printf("\n");
        }

        printf("coefs: %f %f %f \n", a, b, c); //debug
        printf("discr: %f \n", discriminant);     //debug
        puts("Enter new quadratic equation in the following format: ax^2 +- bx +- c = k");
        puts("Or enter 'q' to quit the program");
        stop_ch = getchar();
        if (stop_ch != 'q')
            ungetc(stop_ch, stdin);
        else
            break;
    }
}


void get_coeffs(float * ptr_a, float * ptr_b, float * ptr_c)
{
    char sign;

    scanf("%f", ptr_a);
    while ((sign = getchar()) != '-' && sign != '+')
        continue;
    scanf("%f", ptr_b);
    if (sign == '-')
        *ptr_b = (-1) * *ptr_b ;
    while ((sign = getchar()) != '-' && sign != '+')
        continue;
    scanf("%f", ptr_c);
    if (sign == '-')
        *ptr_c = (-1) * *ptr_c;

}

float make_discriminant(float a, float b, float c)
{
    return b * b - 4 * a * c;
}

void make_roots(float *ptr_x1, float *ptr_x2, float a, float b, float discriminant)
{
    *ptr_x1 = ((-1) * b + pow(discriminant, (float)1/2)) / (2 * a);
    *ptr_x2 = ((-1) * b - pow(discriminant, (float)1/2)) / (2 * a);
}


void clear_input_stream(void)
{
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}
