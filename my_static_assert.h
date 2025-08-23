#ifndef MY_STATIC_ASSERT_H_
#define MY_STATIC_ASSERT_H_

#define my_static_assert(cond) typedef char static_assert_##__LINE__[!!(cond) ? 1 : -1] __attribute__((unused))

#endif //MY_STATIC_AASERT_H
