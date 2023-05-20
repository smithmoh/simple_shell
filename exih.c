#include "main.h"
/**
*handleExit - handles the exit argument 
*@tokens: the argument handler
*Return: always 0
*/
void handleExit(char **tokens)
{
	if (tokens != NULL)
	{
		if (customStrcmp(tokens[0], "exit") == 0)
		{
			exit (0);
		}
	}
}
/**
*exitHandler - exits the shell
*@arg: the argument passed to the func
*/
void exitHandler(char **arg)
{
	int exitStatus;

	if (arg[1] == NULL)
	{
		printf("0 arguments found\n");
		return;
	}
	exitStatus = atoi(arg[1]);
	exit(exitStatus);
}
/**
*handleEnvironment - retrieves environment variables
*@tokens: the no of args passed
*Return: always 0
*/
void handleEnvironment(char **tokens)
{
	char **env = environ;

	if (tokens != NULL)
	{
		if (customStrcmp(tokens[0], "env") == 0)
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
	}
}
