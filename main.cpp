#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_static_assert.h"
#include "my_assert.h"

#include "global_test.h"
#include "interactive_mode.h"
#include "help.h"
#include "prank.h"

// ДЕЛО СДЕЛАНО что происходит до main и после
// до: _start function. This function initializes the program runtime and invokes the program’s main function.
/*
Early low-level initialization, such as:
Configuring processor registers
    Initializing external memory
    Enabling caches
    Configuring the MMU
Stack initialization, making sure that the stack is properly aligned per the ABI requirements
Frame pointer initialization
Initialization of the C/C++ runtime
Initialization of other scaffolding required by the system
Jumping to main
Exiting the program with the return code from main
*/

int main(const int argc, char** argv)
{
    while (true)
    {
        int option_index = 0;
        static struct option long_options[] = {
            {"help",        0, 0, 'h'},
            {"interactive", 0, 0, 'i'},
            {"test",        0, 0, 't'},
            {"prank",       0, 0, 'p'},
            {0} //{0, 0, 0, 0}
        };

        int option_symbol = getopt_long(argc, argv, "hitp", long_options, &option_index);
        if (option_symbol == -1)
            break;

        switch (option_symbol) {
        case 'h':
            // ДЕЛО СДЕЛАНО вынеси в help();
            help(long_options[option_index].name);
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
        case '?':
            break;
        default:
            printf ("?? getopt возвратило код символа 0%d ??\n", option_symbol); //%o
        }
        return 0;
    }
    global_test();
    interactive_mode();
    //MY_ASSERT("Poltorashka" == "dog");
    //MY_ASSERT_WITH_MESSAGE(0 == 1, "переделывай");

    return 0;
}
