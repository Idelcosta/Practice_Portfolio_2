#include "shell_library.h"

/**
*env_list: lists the environ
*/
char **env;
extern char **environ;

void env_list() 
{
    env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}