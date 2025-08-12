#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define EPSILON 1e-7 //используется c fabs вместо discriminant == 0



/*ВОПРОСЫ:
  1. ввод-вывод должен осуществляться через консоль или через файлы?
  2. корни в комплексных числах находить не надо же?))
*/

/*В ПЛАНАХ:
1. Сделать так, чтобы запись "x^2" воспринималась как a = 1, а не a = 0
2. Сделать зацикливание программы, чтобы можно было решать уравнения до написания команды выхода
3. Сделать обработку ошибок пользователя
4. Обработать случай, когда в правой части уравнения находится число, отличное от нуля
*/


int main()
{
    void get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
    float make_discriminant(float a, float b, float c);
    void make_roots(float *ptr_x1, float *ptr_x2, float a, float b, float discriminant);


    float a, b, c;
    float discriminant;
    float x1, x2;

    puts("Enter the quadratic equation in the following format: 2x^2 - 4x + 2 = 0");
    get_coeffs(&a, &b, &c);
    discriminant = make_discriminant(a, b, c);

    if (discriminant < 0)
        puts("This quadratic equation has no solutions in real numbers");
    else if (fabs(discriminant) < EPSILON)
    {
        make_roots(&x1, &x2, a, b, fabs(discriminant));
        puts("The roots of this equation are repeated,");
        printf("so x1 = x2 = %f\n", x2);
    }
    else
    {
        make_roots(&x1, &x2, a, b, discriminant);
        puts("The roots of this equation are:");
        printf("x1 = %f    x2 = %f \n", x1, x2);
    }

    printf("%f %f %f \n", a, b, c);
    printf("%f", discriminant);
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
    while (getchar() != '\n')       //очистка входного потока
        continue;
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

