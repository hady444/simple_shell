#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
int _putchar(char c);
int _puts(char *str);
char *intToString(int number);
int _errputchar(char c);
void _errputs(char *str);
void print_error(char *arg1, char *number, char *arg3);
char *get_command(char *path, char *cmd, struct stat *st);
void _printenv(void);
char **copy_env();
void loop_shell(char **path, char **argv);
void handel_path(char *args[], char **path, char **argv, char **command);
void with_path(char *args[], char **path, char **argv, char **command);
int str_len(char *s);
char *str_cpy(char *dest, char *source);
int str_cmp(char *s1, char *s2);
int str_cmpc(char *s1, const char *s2);
char *str_cat(char *dest, char *src);
char *str_dup(char *str);
int handel_comments(char **token);
void tokenization(char *args[], char **path, char *argv[], char **command);
#endif
