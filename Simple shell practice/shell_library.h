#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>


int main(int ac, char **argv);
char *get_location(char *command);
void execution_command(char **argv);
void exit_function(char **exit_args);
bool check_builtin(char **args, size_t args_count);
void env_list();

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);
char *get_token(char *line_string, char *delimeters);



#endif 