#include "processing.h"

#include <stdio.h>
#include <stdbool.h>

#include "colors_codes.h"
#include "my_assert.h"

// io.h

/**
*   @brief Получает коэффициенты квадратного уравнения
*
*   @param[in] Указатель на структуру, куда будут считаны коэффициенты
*
*   @return[out] Признак ошибки ввода:
*                true - произошла ошибка ввода (считано меньше 3 значений)
*                false - коэффициенты успешно считаны и записаны в структуру
*
*   @note Если ввод некорректен, выводится сообщения об ошибке
**/
bool get_coeffs(struct QuadricCoeffs* ptr_coeffs)
{
    MY_ASSERT(ptr_coeffs != NULL);

    if (scanf("%f %f %f", &(ptr_coeffs->coef_a), &(ptr_coeffs->coef_b), &(ptr_coeffs->coef_c)) != 3)
    {
        puts(RED BOLD "Wrong input. Please, enter the quadratic equation coefficients in the following format: \"a b c\", where ax^2 +- bx +- c = 0\n" RESET RESET);
        return true;
    }
    else
        return false;
}

/**
*  @brief Выводит результат решения квадратного уравнения с цветовым оформлением
*
*  @param[in] result Структура AnswerAndSolution, содержащая данные о решении уравнения
*
*  @note Если `result.solution_case` имеет значение `not_initialized`, выводится сообщение об ошибке
**/
void general_output(struct AnswerAndSolution result)
{
    switch(result.solution_case)   //advisedly added everywhere one more \n to make output more readable
    {
        case inf_roots:
            puts(GREEN "Any x from (-INF; +INF) is the root of this equation\n" RESET);
            break;
        case no_roots:
            puts(GREEN "This equation doesn't have any root\n" RESET);
            break;
        case linear_has_1_root:
        {
            puts(GREEN "This is linear equation and it has one root:" RESET);
            printf(BGGREEN "x = %f" BGDEF "\n\n", result.x1);
            break;
        }
        case quadric_has_1_root:
        {
            printf(GREEN "This quadratic equation has %d root\n" RESET, result.amount_of_roots);
            printf(BGGREEN "x = %f" BGDEF "\n\n", result.x1);
            break;
        }
        case quadric_has_2_roots:
        {
            printf(GREEN "This quadratic equation has %d roots\n" RESET, result.amount_of_roots);
            printf(BGGREEN "x1 = %f     x2 = %f" BGDEF "\n\n", result.x1, result.x2);
            break;
        }
        case quadric_has_0_roots:
        {
            puts(GREEN "This quadratic equation does not have roots in real numbers\n" RESET);
            break;
        }
        case not_initialized:
        {
            puts(RED "Error: solution case does not initialized" RESET);
            break;
        }
        default:
            break;


    }
}

/**
*   @brief Функция очищает входной поток
**/
void clear_input_stream()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}

/**
*   @brief Функция спрашивает у пользователя, желает ли он продолжить ввод
*
*   @return Признак окончания ввода:
*           1 - пользователь желает продолжить ввод
*           -1 - пользователь желает прекратить ввод
**/
int continue_request()
{
    puts(BLUE "Enter new quadratic quadratic equation coefficients in the following format: \"a b c\", where ax^2 + bx + c = 0" RESET);
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
