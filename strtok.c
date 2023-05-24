#include "main.h"
/**
*customStrtok - tokenizes the string
*@buffer: pointer
*@p: pointer
*Return:command
*/
char *customStrtok(char *buffer, char *p)
{
	statics char *nextToken = NULL;
	char *token = NULL;

	if (buffer != NULL)
	{
		nextToken = buffer;
	}
	else if (nextToken == NULL)
	{
		return (NULL);
	}
	while (*nextToken != '\0' && *nextToken == *p)
	{
		nextToken++;
	}
	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}
	return (token);
}
