#ifndef MAIN_H
#define MAIN_H


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_OR    0
#define CMD_NORM  1
#define CMD_AND   2
#define CMD_CHAIN 3

#define CONVERT_UNSIGNED
#define CONVERT_LOWERCASE
#define USE_GETLINE
#define USE_STRTOK
#define HIST_FILE  ".simple_shell_history"
#define HIST_MAX   4096


extern char **environ;
/**
*struct liststr - 
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;




typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;


	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcountt;
} info_t;


char *customStrdup(char *str);
int customStrlen(char *s);
char *customStrcpy(char *dest, char *src);
int customStrcmp(char *s1, char *s2);
char *customStrcat(char *dest, char *src);
char *customStrStr(char *stack, char *needle);
char *customItoa(int n);
void handle_signal(int sign);
int calculate_word(char *buffer);
int calculate_word2(char *buffer);
char *getPath(char *new_command);
char *getDir(char **folder, char *new_command);
void executeCommand(char *new_command);
void displayPrompt(void);
char *getEnvironmentVariable(char *s);
int checkVir(char *buffer, char **new_command);
char *customStrtok(char *buffer, char *p);
void fork_fa(char *buffer, char **new_command, char **argv, int countt);
int *_perror(char *argv, char *str, char *new_command);
int exitHandler(char *buffer, char **new_command);
int free_p(void **ptr);
void replaceVariables(char *line, int exitStatus, int pid);
char *customMemset(char *s, char b, unsigned int n);
void ffree(char *cv);
void *customRealloc(void *ptr, unsigned int oldSize, unsigned int newSize);
char **my_customStrtok(char *buffer, char *delim);
int custom_getline(char **lineptr, size_t *n, FILE *stream);
char *my_custom_getline(void);




#endif
