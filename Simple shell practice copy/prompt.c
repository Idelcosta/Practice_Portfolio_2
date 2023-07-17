#include "shell_library.h"
#include <sys/wait.h>

#define MAX_COMMAND 10

void display_prompt(char **av, char **env)
{
    char *command = NULL;
    int i, status;
    size_t n = 0;
    ssize_t number_character;
    char *tokens;
    pid_t child_pid;

    char *path_copy;
    char *dir;
    char executable;

    char *path = getenv("PATH");


    while (1)
    {
	if (isatty(STDIN_FILENO))
	{
		printf ("cisfun$ ");
	}

        number_character = getline(&command, &n, stdin);
        if (number_character == -1)
        {
            free(command); 
            exit(EXIT_FAILURE);
        }

        i = 0;
        while (command[i])
        {
            if (command[i] == '\n')
            {
                command[i] = 0 ;
            }
            i++;    
        }


        *path_copy = strdup(path);
        *directory = *strtok(path_copy, ";");
        while (tokens != NULL)
        {
            strcpy(executable, directory);
            strcat(executable, "/");
            strcat(executable, command);

            directory = strtok(NULL, ":");
        }

        char *args[] = {command, NULL};


        child_pid = fork();
        if (child_pid == -1)
        {
            free(command);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            execve(executable, args, env);

            perror("execve");
            printf ("%s: No such file or directory\n", av[0]);
            exit(1);
        }
        else
            wait(&status);
    }
}

 
