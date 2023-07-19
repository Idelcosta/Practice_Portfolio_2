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
int _atoi(char *s);
void exit_function(char **exit_args);
bool check_builtin(char **args, size_t args_count);
void env_list();
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *length(char *str);
char *_getenv(char **environ, char *dirname);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);
char* my_strtok(char* str, char *delim);





#endif 