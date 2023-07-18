#include "shell_library.h"

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