#include "../include/help.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/logger.h"

void help()
{
    system("ncal");
    logger_output(LOGGER_PRIORITY_INFO, "help(): calender printed\n");

    printf("parameter help\n");
    printf("--interactive  Sets interactive mode\n");
    printf("--test         Sets the test mode\n");
    printf("--prank        Ha-ha-ha\n");

    printf("Logger priority flags:\n");
    printf("--logger=");
    printf("debug        Sets the fifth logger priority\n");
    printf("info         Sets the fourth logger priority\n");
    printf("warning      Sets the third logger priority\n");
    printf("error        Sets the second logger priority\n");
    printf("critical     Sets the first logger priority\n");
    printf("nothing      There will be no logger_output\n");

    printf("If you do not enter a logger flag, there will be error logging\n");

    logger_output(LOGGER_PRIORITY_INFO, "help(): possible argv printed\n");
}
