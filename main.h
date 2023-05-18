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
	char *dir;
	struct node *next;
}Node;










#endif
