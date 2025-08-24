#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <stdbool.h>

#include "equation_solver.h"

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
bool get_coeffs(QuadricCoeffs* ptr_coeffs);

/**
*  @brief Выводит результат решения квадратного уравнения с цветовым оформлением
*
*  @param[in] result Структура AnswerAndSolution, содержащая данные о решении уравнения
*
*  @note Если `result.solution_case` имеет значение `not_initialized`, выводится сообщение об ошибке
**/
void output_general(AnswerAndSolution result);

/**
*   @brief Функция очищает входной поток
**/
// ХУЙНЯ ПЕРЕДЕЛЫВАЙ - даже в теле функции нет этого ебучего (void)
void clear_input_stream(void);

/**
*   @brief Функция спрашивает у пользователя, желает ли он продолжить ввод
*
*   @return Признак окончания ввода:
*           1 - пользователь желает продолжить ввод
*           -1 - пользователь желает прекратить ввод
**/
int continue_request();

#endif // PROCESSING_H_
