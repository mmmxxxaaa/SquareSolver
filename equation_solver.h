#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

enum SolutionType {
    SOLUTION_TYPE_INF_ROOTS,
    SOLUTION_TYPE_NO_ROOTS,
    SOLUTION_TYPE_LINEAR_HAS_1_ROOT,
    SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT,
    SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS,
    SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS,
    SOLUTION_TYPE_NONE
};

typedef struct {
    float a;
    float b;
    float c;
} QuadricCoeffs;

typedef struct {
    float x1;
    float x2;
    enum SolutionType solution_case;
} AnswerAndSolution;

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
enum SolutionType solve_general(const QuadricCoeffs* ptr_coeffs, AnswerAndSolution* ptr_result);  // mb add right_part later

#endif // EQUATION_SOLVER_H_
