#include <math.h>
#include <stdio.h>

#include "equation_solver.h"
#include "logic_functions.h"
#include "my_assert.h"


static float make_discriminant(struct QuadricCoeffs coeffs);
static void make_roots(float* ptr_x1, float* ptr_x2, struct QuadricCoeffs coeffs, float discriminant);

// solve_quadratic_case
static enum PossibleSolutionCases solve_normal_linear_equation(struct AnswerAndSolution* result, struct QuadricCoeffs coeffs);
static enum PossibleSolutionCases solve_normal_quadratic_equation(struct AnswerAndSolution* result, struct QuadricCoeffs coeffs);

/**
    @brief Функция отвечает за решение уравнения в общем случае и разбивает его на мелкие задачи
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
                inf_roots - бесконечное количество корней
                no_roots - уравнения не является ни линейным, ни квадратным и у него нет корней
                linear_has_1_root - уравнение является линейным и имеет одно решения
                quadric_has_1_root - уравнения является квадратным и имеет одно решение
                quadric_has_2_roots - уравнение является квадратным и имеет два решения
                quadric_has_0_roots - уравнение является квадртаным и не имеет решений
                not_initialized - неинициализированный случай
**/
enum PossibleSolutionCases
general_solution(struct AnswerAndSolution* ptr_result,
                 struct QuadricCoeffs coeffs) // const QuadraticCoeffs* coeffs
{
    MY_ASSERT(ptr_result != NULL); // MY_ASSERT
    MY_ASSERT(is_finite(coeffs.coef_a));
    MY_ASSERT(is_finite(coeffs.coef_b));
    MY_ASSERT(is_finite(coeffs.coef_c));

    if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b) && is_zero(coeffs.coef_c))
        return inf_roots;
    else if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b))
        return no_roots;
    else if (is_zero(coeffs.coef_a))
        return solve_normal_linear_equation(ptr_result, coeffs);
    else
        return solve_normal_quadratic_equation(ptr_result, coeffs);
}

/**
    @brief Функция отвечает за нахождение дискриминанта квадратного уравнения
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] float-значение дискриминанта
**/
// calculate
static float make_discriminant(struct QuadricCoeffs coeffs)
{
    return coeffs.coef_b * coeffs.coef_b - 4 * coeffs.coef_a * coeffs.coef_c;
}

/**
    @brief Функция отвечает за расчёт корней уравнения
    @param[in] ptr_x1 Указатель на переменную, хранящую первый корень
    @param[in] ptr_x2 Указатель на переменную, хранящую первый корень
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[in] discriminant Значение дискриминанта
**/
static void make_roots(float *ptr_x1, float *ptr_x2, struct QuadricCoeffs coeffs, float discriminant)
{
    MY_ASSERT(ptr_x1 != NULL);
    MY_ASSERT(ptr_x2 != NULL);
    MY_ASSERT(ptr_x1 != ptr_x2);
    MY_ASSERT(is_finite(coeffs.coef_a));
    MY_ASSERT(is_finite(coeffs.coef_b));

    float discr_square_root = sqrtf(discriminant);

    float root_1 = ((-1) * coeffs.coef_b + discr_square_root) / (2 * coeffs.coef_a);
    float root_2 = ((-1) * coeffs.coef_b - discr_square_root) / (2 * coeffs.coef_a);

    *ptr_x1 = is_zero(root_1) ? 0.0f : root_1;
    *ptr_x2 = is_zero(root_2) ? 0.0f : root_2;
}

/**
    @brief Функция отвечает за решение уравнения в случае, когда оно линейное
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
                linear_has_1_root - уравнение является линейным и имеет одно решения
**/
static enum PossibleSolutionCases solve_normal_linear_equation(struct AnswerAndSolution* ptr_result, struct QuadricCoeffs coeffs)
{
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(coeffs.coef_b));
    MY_ASSERT(is_finite(coeffs.coef_c));

    float root = -coeffs.coef_c/coeffs.coef_b;
    ptr_result->x1 = is_zero(root) ? 0.0f : root;  //avoiding -0.0 case
    ptr_result->x2 = ptr_result->x1;
    ptr_result->amount_of_roots = 1;

    return linear_has_1_root;
}

/**
    @brief Функция отвечает за решение уравнения в общем случае и разбивает его на мелкие задачи
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
                quadric_has_1_root - уравнения является квадратным и имеет одно решение
                quadric_has_2_roots - уравнение является квадратным и имеет два решения
                quadric_has_0_roots - уравнение является квадртаным и не имеет решений
**/
static enum PossibleSolutionCases solve_normal_quadratic_equation(struct AnswerAndSolution* ptr_result, struct QuadricCoeffs coeffs)
{
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(coeffs.coef_a));
    MY_ASSERT(is_finite(coeffs.coef_b));
    MY_ASSERT(is_finite(coeffs.coef_c));

    float discriminant = make_discriminant(coeffs);

    if (discriminant < 0)
    {
        ptr_result->amount_of_roots = 0;
        return quadric_has_0_roots;
    }

    if (is_zero(discriminant))
    {
        make_roots(&(ptr_result->x1), &(ptr_result->x2), coeffs, fabs(discriminant));
        ptr_result->amount_of_roots = 1;

        return quadric_has_1_root;
    }
    else
    {
        make_roots(&(ptr_result->x1), &(ptr_result->x2), coeffs, discriminant);
        ptr_result->amount_of_roots = 2;

        return quadric_has_2_roots;
    }
}

