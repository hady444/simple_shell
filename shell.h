#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
/*typedef struct Node*/
/*{*/
/*	char *dir_path;*/
	/*struct Node *next;*/
/*} Node;*/

void _getenv(const char *com, char **path);
char *intToString(int number);
void print_error(char *arg1, char *number, char *arg3);
char *get_command(char *path, char *cmd, struct stat *st);
void _printenv(void);
void loop_shell(char **argv, int *status);
void handel_path(char *args[], char **argv, char **command, int *status);
void with_path(char *args[], char **path, char **path1, char **argv,
char **command, int *status);
int str_len(char *s);
char *str_cpy(char *dest, char *source);
int str_cmp(char *s1, char *s2);
int str_cmpc(char *s1, const char *s2);
char *str_cat(char *dest, char *src);
char *str_dup(char *str);
int handel_comments(char **token);
int tokenization(char *args[], char *argv[], char **command, int *status);
int check_empty_env(void);
int exit_me(int *status);
#endif
