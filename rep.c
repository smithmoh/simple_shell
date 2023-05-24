#include "main.h"
#include <stdio.h>

#define MAX_BUFFSIZE_SIZE 1024

/**
* replaceVariables - replaces variables
* @line: input string
* @exitStatuss: exitstatus value
* @pid: the process pid
*/
void replaceVariables(char *line, int exitStatus, int pid)
{
	char buffer[MAX_BUFFSIZE_SIZE];
	char *variable = NULL;
	char *replacement = NULL;
	char *pos = NULL;

	variable = "$?";
	sprintf(buffer, "%d", exitStatus);
	replacement = buffer;
	while ((pos = customStrStr(line, variable)) != NULL)
	{
		size_t varlen = customStrlen(variable);
		size_t replen = customStrlen(replacement);
		size_t taillen = customStrlen(pos + varlen);

		memmove(pos + replen, pos + varlen, taillen + 1);
		memcpy(pos, replacement, replen);
	}
	variable = "$$";
	sprintf(buffer, "%d", pid);
	customStrcpy(replacement, buffer);
	while ((pos = customStrStr(line, variable)) != NULL)
	{
		size_t varlen = customStrlen(variable);
		size_t replen = customStrlen(replacement);
		size_t taillen = customStrlen(pos + varlen);

		memmove(pos + replen, pos + varlen, taillen + 1);
		memcpy(pos, replacement, replen);
	}
}
