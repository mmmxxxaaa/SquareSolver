#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_static_assert.h"
// #include "my_assert.h"

#include "global_test.h"
#include "interactive_mode.h"
#include "help.h"
#include "prank.h"

#include "logger.h"

int main(const int argc, char** argv)
{
    while (true)
    {
        int option_index = 0;
        static struct option long_options[] = {
            {"help",         0, 0, 'h'},
            {"interactive",  0, 0, 'i'},
            {"test",         0, 0, 't'},
            {"prank",        0, 0, 'p'},
            {"debug_log",    0, 0, 'd'},
            {"info_log",     0, 0,  0}, //во избежание совпадения коротких флагов, не будет короткого флага
            {"warning_log",  0, 0, 'w'},
            {"error_log",    0, 0, 'e'},
            {"critical_log", 0, 0, 'c'},
            {0} //{0, 0, 0, 0}
        };

        int option_symbol = getopt_long(argc, argv, "hitp", long_options, &option_index);
        if (option_symbol == -1)
            break;

        enum LoggerPriority logger_type = LOGGER_PRIORITY_NOTHING;

        switch (option_symbol) {
        case 'h':
            help();  //FIXME во все функции дальше передавать logger_type
            break;
        case 'i':
            interactive_mode();
            break;
        case 't':
            global_test();
            break;
        case 'p':
            prank();
            break;
        case 'd':
            logger_type = LOGGER_PRIORITY_DEBUG;
            break;
        case 0:
            logger_type = LOGGER_PRIORITY_INFO;
            break;
        case 'w':
            logger_type = LOGGER_PRIORITY_WARNING;
            break;
        case 'e':
            logger_type = LOGGER_PRIORITY_ERROR;
            break;
        case 'c':
            logger_type = LOGGER_PRIORITY_CRITICAL; //FIXME - в отдельную функцию
            break;
        case '?':
            break;
        default:
            printf ("?? getopt возвратило код символа 0%d ??\n", option_symbol); //%o
        }
        return 0;
    }
    interactive_mode();

    //MY_ASSERT("Poltorashka" == "dog");
    //MY_ASSERT_WITH_MESSAGE(0 == 1, "переделывай");

    return 0;
}
