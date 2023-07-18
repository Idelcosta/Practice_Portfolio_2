#include "shell_library.h"
#include <sys/wait.h>


int main(int ac, char **argv)
{
    char *string = NULL, *string_copy = NULL;
    int i, j, status;
    size_t n = 0;
    ssize_t number_character;
    pid_t child_pid;`
    char *arguments;
    int arguments_count = 0;
    int i;

    (void)ac;

    while (1)
    {
	if (isatty(STDIN_FILENO))
	{
		printf ("cisfun$ ");
	}

        number_character = getline(&string, &n, stdin);
        if (number_character == -1)
        {
            free(string); 
            exit(EXIT_FAILURE);
        }

        string_copy = malloc(sizeof(char) * number_character);
        if (string_copy == NULL)
        {
            perror("error memory allocation");
            return (-1);
        }

        strcpy(string_copy, string);

        arguments = strtok(string, " \n");

        while (arguments != NULL)
        {
            arguments_count++;
            arguments = strtok(NULL, " \n");
        }
        arguments_count++;

        argv = malloc(sizeof(char *) * arguments_count);

        arguments = strtok(string_copy, " \n");

        for (i = 0; arguments != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(arguments));
            strcpy(argv[i], arguments);

            arguments = strtok(NULL, " \n");
        }
        argv[i] = NULL;



        // i = 0;
        // while (string[i])
        // {
        //     if (string[i] == '\n')
        //     {
        //         string[i] = 0 ;
        //     }
        //     i++;    
        // }

        // j = 0;
        // argv[j] = strtok(string, " \n");
        // while (argv[j])
        // {
        //     j++;
        //     argv[j] = strtok(NULL, " \n");
        // }


        child_pid = fork();
        if (child_pid == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            execution_command(argv);
        }
        else
            wait(&status);
    }

    free(string);
    free(string_copy);

    return(0);
}

 
