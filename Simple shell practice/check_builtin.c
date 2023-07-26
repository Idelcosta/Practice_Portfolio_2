#include "shell_library.h"

/**
*check_builtin - checks the presence of builtin commands
*@args: the arguments to be checked
*@args_count: the size of the args
*
*Return: True if builtin exists and False if not
*/
bool check_builtin(char **args, size_t args_count)
{
    (void)args_count;
    
    if (_strcmp(args[0], "exit") == 0)
    {
        exit_function(args);
    }

    else if ((_strcmp(args[0], "env") == 0) || (_strcmp(args[0], "printenv") == 0))
    {
        env_list(void);
        return(true);
    }

    return(false);  
}