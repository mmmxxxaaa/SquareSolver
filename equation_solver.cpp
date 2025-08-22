#include "equation_solver.h"

#include <math.h>
#include <stdio.h>

#include "my_assert.h"
#include "logic_functions.h"

static float make_discriminant(struct QuadricCoeffs coeffs);
static void make_roots(float* ptr_x1, float* ptr_x2,
                       struct QuadricCoeffs coeffs, float discriminant);

static enum SolutionType solve_normal_linear_equation(struct QuadricCoeffs coeffs,
                                                      struct AnswerAndSolution* result);
static enum SolutionType solve_normal_quadratic_equation(struct QuadricCoeffs coeffs,
                                                         struct AnswerAndSolution* result);

/**
    @brief Функция отвечает за решение уравнения в общем случае и разбивает его на мелкие задачи
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
        SOLUTION_TYPE_INF_ROOTS - бесконечное количество корней
        SOLUTION_TYPE_NO_ROOTS - уравнения не является ни линейным, ни квадратным и у него нет корней
        SOLUTION_TYPE_LINEAR_HAS_1_ROOT - уравнение является линейным и имеет одно решения
        SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT - уравнения является квадратным и имеет одно решение
        SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS - уравнение является квадратным и имеет два решения
        SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS - уравнение является квадртаным и не имеет решений
        SOLUTION_TYPE_NONE - неинициализированный случай
**/
enum SolutionType solve_general(struct QuadricCoeffs coeffs, struct AnswerAndSolution* ptr_result)
{
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(coeffs.a));
    MY_ASSERT(is_finite(coeffs.b));
    MY_ASSERT(is_finite(coeffs.c));

    if (is_zero(coeffs.a) && is_zero(coeffs.b) && is_zero(coeffs.c))
        return SOLUTION_TYPE_INF_ROOTS;
    else if (is_zero(coeffs.a) && is_zero(coeffs.b))
        return SOLUTION_TYPE_NO_ROOTS;
    else if (is_zero(coeffs.a))
        return solve_normal_linear_equation(coeffs, ptr_result);
    else
        return solve_normal_quadratic_equation(coeffs, ptr_result);
}

/**
    @brief Функция отвечает за нахождение дискриминанта квадратного уравнения
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] float-значение дискриминанта
**/
static float make_discriminant(struct QuadricCoeffs coeffs)
{
    return coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
}

/**
    @brief Функция отвечает за расчёт корней уравнения
    @param[in] ptr_x1 Указатель на переменную, хранящую первый корень
    @param[in] ptr_x2 Указатель на переменную, хранящую первый корень
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[in] discriminant Значение дискриминанта
**/
static void make_roots(float *ptr_x1, float *ptr_x2, struct QuadricCoeffs coeffs,
                       float discriminant)
{
    MY_ASSERT(ptr_x1 != NULL);
    MY_ASSERT(ptr_x2 != NULL);
    MY_ASSERT(ptr_x1 != ptr_x2);
    MY_ASSERT(is_finite(coeffs.a));
    MY_ASSERT(is_finite(coeffs.b));

    float discr_square_root = sqrtf(discriminant);

    float root_1 = ((-1) * coeffs.b + discr_square_root) / (2 * coeffs.a);
    float root_2 = ((-1) * coeffs.b - discr_square_root) / (2 * coeffs.a);

    *ptr_x1 = is_zero(root_1) ? 0.0f : root_1;
    *ptr_x2 = is_zero(root_2) ? 0.0f : root_2;
}

/**
    @brief Функция отвечает за решение уравнения в случае, когда оно линейное
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
            SOLUTION_TYPE_LINEAR_HAS_1_ROOT - уравнение является линейным и имеет одно решения
**/
static enum SolutionType solve_normal_linear_equation(struct QuadricCoeffs coeffs,
                                                      struct AnswerAndSolution* ptr_result)
{
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(coeffs.b));
    MY_ASSERT(is_finite(coeffs.c));

    float root = -coeffs.c/coeffs.b;
    ptr_result->x1 = is_zero(root) ? 0.0f : root;  //avoiding -0.0 case
    ptr_result->x2 = ptr_result->x1;

    return SOLUTION_TYPE_LINEAR_HAS_1_ROOT;
}

/**
    @brief Функция отвечает за решение уравнения в общем случае и разбивает его на мелкие задачи
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
                SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT - уравнения является квадратным и имеет одно решение
                SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS - уравнение является квадратным и имеет два решения
                SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS - уравнение является квадртаным и не имеет решений
**/
static enum SolutionType solve_normal_quadratic_equation(struct QuadricCoeffs coeffs,
                                                         struct AnswerAndSolution* ptr_result)
{
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(coeffs.a));
    MY_ASSERT(is_finite(coeffs.b));
    MY_ASSERT(is_finite(coeffs.c));

    float discriminant = make_discriminant(coeffs);

    if (discriminant < 0)
        return SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS;
    make_roots(&(ptr_result->x1), &(ptr_result->x2), coeffs, fabs(discriminant));
    if (is_zero(discriminant))
        return SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT;
    else
        return SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS;
}
