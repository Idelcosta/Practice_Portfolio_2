#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell_library.h"

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);

        // Remove the newline character from the end
        command[strcspn(command, "\n")] = '\0';

        // Check if the user pressed Ctrl+D (end of file)
        if (feof(stdin)) {
            printf("\n");
            break;
        }

        // Fork a child process to execute the command
        pid_t pid = fork();

        if (pid == -1) {
            // Error while forking
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process

            // Split the command and search for the executable in the PATH
            char *path = getenv("PATH");
            char *path_copy = strdup(path);
            char *dir = strtok(path_copy, ":");

            while (dir != NULL) {
                char executable[MAX_COMMAND_LENGTH];
                snprintf(executable, sizeof(executable), "%s/%s", dir, command);

                // Attempt to execute the command
                if (access(executable, X_OK) == 0) {
                    // Executing the command
                    execl(executable, command, NULL);

                    // If execl returns, an error occurred
                    perror("execl");
                    exit(1);
                }

                dir = strtok(NULL, ":");
            }

            // If the loop completes without finding the command
            printf("Command not found: %s\n", command);
            exit(1);
        } else {
            // Parent process
            int status;
            wait(&status);

            // Check if the child process exited successfully
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Child process exited with status: %d\n", exit_status);
            } else {
                printf("Child process terminated abnormally\n");
            }
        }
    }

    return 0;
}
