#include "main.h"

#define MAX_BUFFSIZE_SIZE 1024

/**
*replaceVariables - replaces variables
*@line: input string
*@exitStatus: exitstatus value
*@pid: the process pid
*/
void replaceVariables(char *line, int exitStatus, int pid)
{
	char buffer(MAX_BUFFER_SIZE);
	char *variable = NULL;
	char *replacement = NULL;
	char *pos = NULL;

	variable = "$?";
	sprintf(buffer, sizeof(buffer), "%d", exit_status);
	replacement = buffer;
	while ((pos = customStrStr(line, variable)) != NULL)
	{
		size_t varLen = customStrlen(variable);
		size_t repLen = customStrlen(replacement);
		size_t tailLen = customStrlen(pos + varLen);

		memmove(pos + repLen, pos + varLen, tailLen + 1);
		memcpy(pos, replacement, repLen);
	}
	variable = "$$";
	snprintf(buffer, sizeof(buffer), "%d", pid);
	replacement = buffer;
	while ((pos = customStrStr(line, variable)) != NULL)
	{
		size_t varLen = customStrlen(variable);
		size_t repLen = customStrlen(replacement);
		size_t tailLen = customStrlen(pos + varLen);

		memmove(pos + repLen, pos + varLen, tailLen + 1);
		memcpy(pos, replacement, repLen);
	}
}
