#include "shell_library.h"

#define MAX_COMMAND 10
#define MAX_COMMAND_LENGTH 100

void display_prompt(char **av, char **env)
{
    char *command = NULL;
    int i, status;
    size_t n = 0, number_character;
    char *args[MAX_COMMAND];
    pid_t child_pid;

    char *path_copy, *directory;
    char executable[MAX_COMMAND_LENGTH];
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
            fflush(stdout);
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


        path_copy = strdup(path);
        directory = strtok(path_copy, " \n");
        while (directory != NULL)
        {
            strcpy(executable, directory);
            strcat(executable, "/");
            strcat(executable, command);

            directory = strtok(NULL, " \n");
        }

        args[0] = command;


        child_pid = fork();
        if (child_pid == -1)
        {
            free(command);
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            if (execve(executable, args, env) == -1)
            {
                printf ("%s: No such file or directory\n", av[0]);
            }
        }

        else
            wait(&status);
    }
}

 
