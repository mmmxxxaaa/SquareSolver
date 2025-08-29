#include "../include/prank.h"

#include <stdio.h>
#include <unistd.h>
//#include <time.h>

#include "../include/colors_codes.h"
#include "../include/io.h"
#include "../include/equation_solver.h"
#include "../include/my_assert.h"
#include "../include/logger.h"

/*
const int thinking_time_long = 4;
const int thinking_time_short = 2;

static void thinking_silent(time_t thinking_time);
static void thinking_shout(time_t thinking_time);
*/

void prank()
{
    const int prank_number = 10;

    puts(BLUE "Enter new quadratic quadratic equation coefficients"
        " in the following format: \"a b c\", where ax^2 + bx + c = 0" RESET);
    for (int i = 0; i < prank_number; i++)
    {
        QuadricCoeffs coeffs = {0};

        bool got_success = get_coeffs(&coeffs);
        clear_input_stream();

        if (got_success)
        {
            logger_output(LOGGER_PRIORITY_INFO, "prank(): starting processing_prank()\n");
            processing_prank();
            break;

        }
        if (continue_request() == -1)
        {
            logger_output(LOGGER_PRIORITY_ERROR, "prank(): wrong input coefficients\n");
            break;
        }
    }
}

void processing_prank()
{
    printf("Are you sure that the a coefficient is 0?\n");
    clear_input_stream();
    printf("OK :-) \n");
    printf("starting thinking\n");

/*
    thinking_silent(thinking_time_long);

    thinking_shout(thinking_time_short);

    thinking_silent(thinking_time_long);

    thinking_shout(thinking_time_short);
*/

    loading_bar_imitation();

    printf("The answer is POGLYAD POLTORASHKY\n");
    poltoraIIIka("MEOW");
    logger_output(LOGGER_PRIORITY_INFO, "printed poltoraIIIka result\n");
}

void poltoraIIIka(const char *name)
{
    MY_ASSERT(name != NULL);

    printf(" ");
    printf(" \n");
    printf("       ....／＞　 フ.....\n"
           "　　　　　| 　_　 _|\n"
           "　 　　　／`ミ _* 彡 -- %s!!\n"
           "　　 　 /　　　 　 |\n"
           "　　　 /　 ヽ　　 ﾉ\n"
           "　／￣|　　 |　|　|\n"
           "　| (￣ヽ＿_ヽ_)_)\n"
           "　＼二つ\n", name);
    printf(" \n");
    printf(" ");
}

/*
void thinking_silent(time_t thinking_time)
{
    time_t start_time, end_time;
    time(&start_time);
    while ((time(&end_time) - start_time) < thinking_time)
        ;
}

void thinking_shout(time_t thinking_time)
{
    time_t start_time, end_time;
    time(&start_time);
    while ((time(&end_time) - start_time) < thinking_time)
        printf("thinking\n");
}
*/


void loading_bar_imitation()
{
    printf("▰▱▱▱▱▱▱▱▱▱ 10%%\n");
    sleep(1);

    printf("▰▰▱▱▱▱▱▱▱▱ 20%%\n");
    sleep(1);

    printf("▰▰▰▱▱▱▱▱▱▱ 30%%\n");
    sleep(1);

    printf("▰▰▰▰▱▱▱▱▱▱ 40%%\n");
    sleep(1);

    printf("▰▰▰▰▰▱▱▱▱▱ 50%%\n");
    sleep(1);

    printf("▰▰▰▰▰▰▱▱▱▱ 60%%\n");
    sleep(1);

    printf("▰▰▰▰▰▰▰▱▱▱ 70%%\n");
    sleep(1);

    printf("▰▰▰▰▰▰▰▰▱▱ 80%%\n");
    sleep(1);

    printf("▰▰▰▰▰▰▰▰▰▱ 90%%\n");
    sleep(1);

    printf("▰▰▰▰▰▰▰▰▰▰ 100%%\n");
    sleep(1);
}
