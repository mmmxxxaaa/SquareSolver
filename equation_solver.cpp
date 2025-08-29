#include "equation_solver.h"

#include <math.h>
#include <stdio.h>

#include "my_assert.h"
#include "logic_functions.h"
#include "logger.h"

/**
    @brief Функция отвечает за нахождение дискриминанта квадратного уравнения
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] float-значение дискриминанта
**/
static float make_discriminant(const QuadricCoeffs* coeffs);

/**
    @brief Функция отвечает за решение уравнения в случае, когда оно линейное
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
            SOLUTION_TYPE_LINEAR_HAS_1_ROOT - уравнение является линейным и имеет одно решения
**/
static enum SolutionType solve_linear_equation(const QuadricCoeffs* ptr_coeffs,
                                                      RootsAndCase* ptr_result);

/**
    @brief Функция отвечает за решение уравнения в общем случае и разбивает его на мелкие задачи
    @param[in] ptr_result Указатель на структуру, в которой хранится всё, связанное с решением
    @param[in] coeffs Структура с коэффициентами квадратного уравнения
    @param[out] enum-значение частного случая квадратного уравнения:
        SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT - уравнения является квадратным и имеет одно решение
        SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS - уравнение является квадратным и имеет два решения
        SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS - уравнение является квадртаным и не имеет решений
**/
static enum SolutionType solve_quadratic_equation(const QuadricCoeffs* ptr_coeffs,
                                                         RootsAndCase* ptr_result);

void swap_roots(float* ptr_root_1, float* ptr_root_2);

enum SolutionType solve_general(const QuadricCoeffs* ptr_coeffs, RootsAndCase* ptr_result)
{
    MY_ASSERT(ptr_coeffs != NULL);
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(ptr_coeffs->a));
    MY_ASSERT(is_finite(ptr_coeffs->b));
    MY_ASSERT(is_finite(ptr_coeffs->c));

    if (is_zero(ptr_coeffs->a) && is_zero(ptr_coeffs->b) && is_zero(ptr_coeffs->c))
    {
        logger_output("Solution type chosen: SOLUTION_TYPE_INF_ROOTS\n", LOGGER_PRIORITY_INFO);
        return SOLUTION_TYPE_INF_ROOTS;
    }
    else if (is_zero(ptr_coeffs->a) && is_zero(ptr_coeffs->b))
    {
        logger_output("Solution type chosen: SOLUTION_TYPE_NO_ROOTS\n", LOGGER_PRIORITY_INFO);
        return SOLUTION_TYPE_NO_ROOTS;
    }
    else if (is_zero(ptr_coeffs->a))
    {
        logger_output("Solution type chosen: SOLUTION_TYPE_LINEAR_ROOTS; Starting searching root\n",
            LOGGER_PRIORITY_INFO);
        return solve_linear_equation(ptr_coeffs, ptr_result);
    }
    else
    {
        logger_output("It is a quadratic equation; Starting searching root\n",
            LOGGER_PRIORITY_INFO);
        return solve_quadratic_equation(ptr_coeffs, ptr_result);
    }
}

static float make_discriminant(const QuadricCoeffs* ptr_coeffs)
{
    MY_ASSERT(ptr_coeffs != NULL);
    MY_ASSERT(is_finite(ptr_coeffs->a));
    MY_ASSERT(is_finite(ptr_coeffs->b));
    MY_ASSERT(is_finite(ptr_coeffs->c));

    return (ptr_coeffs->b) * (ptr_coeffs->b) - 4 * (ptr_coeffs->a) * (ptr_coeffs->c);
}

static enum SolutionType solve_linear_equation(const QuadricCoeffs* ptr_coeffs,
                                                     RootsAndCase* ptr_result)
{
    MY_ASSERT(ptr_coeffs != NULL);
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(ptr_coeffs->b));
    MY_ASSERT(is_finite(ptr_coeffs->c));

    float root = -ptr_coeffs->c/ptr_coeffs->b;
    ptr_result->x1 = is_zero(root) ? 0.0f : root;  //avoiding -0.0 case
    ptr_result->x2 = ptr_result->x1;

    return SOLUTION_TYPE_LINEAR_HAS_1_ROOT;
}

static enum SolutionType solve_quadratic_equation(const QuadricCoeffs* ptr_coeffs,
                                                        RootsAndCase* ptr_result)
{
    MY_ASSERT(ptr_coeffs != NULL);
    MY_ASSERT(ptr_result != NULL);
    MY_ASSERT(is_finite(ptr_coeffs->a));
    MY_ASSERT(is_finite(ptr_coeffs->b));
    MY_ASSERT(is_finite(ptr_coeffs->c));

    float discriminant = make_discriminant(ptr_coeffs);

    if (discriminant < 0)
        return SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS;

    float discr_square_root = sqrtf(discriminant);

    float root_1 = ((-1) * ptr_coeffs->b + discr_square_root) / (2 * ptr_coeffs->a);
    float root_2 = ((-1) * ptr_coeffs->b - discr_square_root) / (2 * ptr_coeffs->a);

    if (root_1 < root_2) //нужно для упрощения тестов (первый ожидаемый вводимый корень наибольший)
        swap_roots(&root_1, &root_2);

    ptr_result->x1 = is_zero(root_1) ? 0.0f : root_1;
    ptr_result->x2 = is_zero(root_2) ? 0.0f : root_2;

    if (is_zero(discriminant))
        return SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT;
    else
        return SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS;
}


void swap_roots(float* ptr_root_1, float* ptr_root_2)
{
    float tmp = *ptr_root_1;

    *ptr_root_1 = *ptr_root_2;
    *ptr_root_2 = tmp;

    printf("%s: root_1 = %f, root_2 = %f \n", __func__, *ptr_root_1, *ptr_root_2);
}
