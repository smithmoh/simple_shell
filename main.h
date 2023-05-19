#ifndef MAIN_H
#define MAIN_H


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct node 
{
	char *str;
	struct node *next;
}Node;

typedef struct 
{
	char *last_token;
}tokenise;


#define TOKEN_BUFSIZE 1024
#define BUF_SIZE 1024
#define TOKEN_SEPERATOR "\t\r\n\a,;:"

extern char **environ;
/**
 *its a global variable
 */

void displayPrompt(void);
char *readLine(void);
char **parseLine(char *new_command);

char *findExecutable(char **tokens);
int executeChildProcess(char *command_path, char **tokens);
void handleEnvironment(char **tokens);
void handleExit(char **tokens);
void exitHandler(char **arg);
char *getEnvironmentVariable(char *name);
Node *createPathLinkedList;

char **handleSeperators(char *new_command);
int changeDirectory(char **args);
ssize_t customGetline(char **new_command, size_t *n, FILE *stream);
int _setenev(char *name, char *value, int overwrite);
int _unsetenev(char *name);
void applyOperand(char *new_command);
char* _customStrtok(tokenise *str, char* string, const char* delimiter);
char *My_customStrchr(const char *str, int c);


int customStrcmp(char *s1, char *s2);
char *customStrchr(char *s, char c);
char *customStrdup(char *str);
int customAtoi(char *str);
char *customMemcpy(char *dest, char *src, size_t size);

void *customRealloc(void *oldPtr, int oldSize, int size);
char *customStrcpy(char *dest, char *src);
char *customStrcat(char *dest, char *src);
char *customStrncpy(char *dest, char *src, int n);
int customStrlen(char *s);
void freeTokens(char **tokens);
int cusotmStrncmp(char *s1, char *s2, int n);






#endif
