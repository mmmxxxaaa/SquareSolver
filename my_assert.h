#ifndef MY_ASSERT_H_
#define MY_ASSERT_H

#define my_assert(constant_expression) my_assert_function(constant_expression, __FILE__, __LINE__)

void my_assert_function(int constant_expression, const char* name_of_file, int number_of_line);

#endif
