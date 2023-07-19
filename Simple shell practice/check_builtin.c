#include "shell_library.h"

bool check_builtin(char **args, size_t args_count)
{
    (void)args_count;
    
    if (_strcmp(args[0], "exit") == 0)
        exit_function(args);

    else if ((_strcmp(args[0], "env") == 0) || (_strcmp(args[0], "printenv") == 0))
    {
        env_list();
        return(true);
    }

    return(false);  
}