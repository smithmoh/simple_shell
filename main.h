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

#define BUFFER_SIZE 1024

ssize_t read_line(char *buffer, size_t size);
int execute_command(const char *command);









#endif
