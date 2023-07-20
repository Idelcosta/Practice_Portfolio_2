#include "shell_library.h"

/**
*exit_function: exit builtin that exits the shell
*@exit_args: argument of exiting
*/
void exit_function(char **exit_args)
{
    int status = EXIT_SUCCESS;

    if (exit_args[1])
    {
        status = _atoi(exit_args[1]);
    }

    free(exit_args);
    exit(status);
 }