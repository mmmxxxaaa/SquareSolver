#ifndef LOGIC_FUNCTIONS_TEST_H_
#define LOGIC_FUNCTIONS_TEST_H_

int test_is_zero(float number, bool expecting_value);
int test_is_equal(float number_1, float number_2, bool expecting_value);
int test_is_nan(float number, bool expecting_value);
int test_is_inf(float number, bool expecting_value);
int test_is_finite(float number, bool expecting_value);

#endif // LOGIC_FUNCTIONS_TEST_H_
