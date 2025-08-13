#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define EPSILON 1e-7 //using with fabs instead discriminant == 0



/*Questions:
    How to print +- symbol as one symbol
    ��������, ����� ����������� �� ������������ ������ ���������, � ����� ��������� ��� � ������ � ��� �������� � ���
*/

/*Plans:
1. Make the entry "x^2" be interpreted as a = 1 instead of a = 0 and "x" as b = 1 instead of b = 0
2. Add zero coefficient recognition
3. Do user error handling
*/

//������� �� ������������ ����, � ����� ������


/*Remake:
1. a, b, c -> coef_a, coef_b, coef_c
2. functions prototypes are outside main() now

*/


//void get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
float make_discriminant(float coef_a, float coef_b, float coef_c);
void make_roots(float *ptr_x1, float *ptr_x2, float coef_a, float coef_b, float discriminant);
void clear_input_stream(void);

/*
void get_a(float *ptr_a);
void get_b(float *ptr_b);
void get_c(float *ptr_c);
void get_to_next_coef(void);
*/

int main(void)
{
    char stop_ch = 'w';

    puts("Enter the quadratic equation in the following format: ax^2 +- bx +- c = k");
    while (stop_ch != 'q')
    {
        float coef_a, coef_b, coef_c, right_part;
        float discriminant;
        float x1, x2;
        char ch;


        get_coeffs(&coef_a, &coef_b, &coef_c);
        while ((ch = getchar()) != '\n' && ch != EOF)  //searching for right_part
            if (ch == '=')
            {
                scanf("%f", &right_part);
                break;
            }
        coef_c -= right_part;
        clear_input_stream();



        discriminant = make_discriminant(coef_a, coef_b, coef_c);

        if (discriminant < 0)
        {
            puts("This quadratic equation has no solutions in real numbers");
            printf("\n");
        }
        else if (fabs(discriminant) < EPSILON)
        {
            make_roots(&x1, &x2, coef_a, coef_b, fabs(discriminant));
            puts("The roots of this equation are repeated,");
            printf("so x1 = x2 = %f\n", x2);
            printf("\n");
        }
        else
        {
            make_roots(&x1, &x2, coef_a, coef_b, discriminant);
            puts("The roots of this equation are:");
            printf("x1 = %f    x2 = %f \n", x1, x2);
            printf("\n");
        }

        printf("coefs: %f %f %f \n", coef_a, coef_b, coef_c); //debug
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

void get_to_next_coef(void)
{
    char sign;
    while ((sign = getchar()) != '-' && sign != '+' && sign != '=')
        continue;


}


/*
void get_a(float *ptr_a)
{
    char ch, ch_1, ch_2;
    char degree;

    ch = getchar();
    if (ch == 'x' || ch == '-')
    {
        if (ch == '-' && (ch_1 = getchar()) == 'x' && (ch_2 = getchar()) == '^')     ��� ��� �� ������ � ������������ �
            *ptr_a = -1;                                                             � ��������� ������������ �� ����� if-else
        else                                                                         ����� ����������� ��������� ��������� � ������ ��������
        {
            ch = getchar();
            if (ch == '^')
            {
                scanf("%d", &degree)
                if (degree == 2)
                    *ptr_a = 1;
                else
                {
                    puts("������: ����������� ������� ������� (���� ��� ������ 2)")
                    exit(1); //����� ���-�� ������ ��� ���������?
                }
            }

        }
    }

}
*/



/*   ������� ����������� �� � ����� �������, �� ��� ����� ��������� (������� ���� ���� �� 40% �� ������)
     ���� ���� ����������� ������� �� �� 4 �������, ����������������� � ����������, �� �� ��������� �
     ��, ��� ��� ������������ ����� ���������� ������, �������� �� x^2 ��� ������ x
void get_coeffs(float * ptr_a, float * ptr_b, float * ptr_c)
{
    char sign;
    char ch;
    int degree;

    ch = getchar();
    if (ch == 'x')
    {
        ch = getchar();
        if (ch == '^')
        {
            scanf("%d", &degree);
            if (degree == 2)             //�������� ��������� ������, ����� degree != 2
            {
                *ptr_a = 1;
                while ((sign = getchar()) != '-' && sign != '+' && sign != '=')
                    continue;
                if (sign == '=') //��������� ������ x^2 = k
                    *ptr_b = 0;
                    *ptr_c = 0;
                    ungetc(sign, stdin);
                while ((ch = getchar()) == ' ')
                    continue;
                if (ch == 'x')   //��������� ������ x^2
                {
                    *ptr_b = 1;
                }
                else
                {
                    ungetc(ch, stdin);
                    scanf("%f", ptr_b);
                    while ((sign = getchar()) != '-' && sign != '+' && sign != '=')
                        continue;
                    if (sign == '=')
                    {
                        *ptr_c = 0;
                        ungetc(sign, stdin); //returning back the '=' to find the right_part in the main()
                    }
                    else
                    {
                        scanf("%f", ptr_c);
                        if (sign == '-')
                            *ptr_c = (-1) * *ptr_c;
                    }

                }

            }
        }
        else
        {
        *ptr_a = 0;
        *ptr_b = 1;
        while ((sign = getchar()) != '-' && sign != '+')
            continue;
        scanf("%f", ptr_c);
        if (sign == '-')
            *ptr_c = (-1) * *ptr_c;
        }
    }

    else
    {
        ungetc(ch, stdin);
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
*/

}

float make_discriminant(float coef_a, float coef_b, float coef_c)
{
    return coef_b * coef_b - 4 * coef_a * coef_c;
}

void make_roots(float *ptr_x1, float *ptr_x2, float coef_a, float coef_b, float discriminant)
{
    *ptr_x1 = ((-1) * coef_b + pow(discriminant, (float)1/2)) / (2 * coef_a);
    *ptr_x2 = ((-1) * coef_b - pow(discriminant, (float)1/2)) / (2 * coef_a);
}

void clear_input_stream(void)
{
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}
