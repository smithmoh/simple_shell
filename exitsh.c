#include "main.h"
/**
*customStrcmp - compares two strings
*@s1: 1st string
*@s2: 2nd string
*Return: always 0
*/
int customStrcmp(char *s1, char *s2)
{
	int v;

	for (v = 0; s1[v] && s2[v] && s1[v] == s2[v]; v++)
		;
	return (s1[v] - s2[v]);
}
/**
*checkVir - checks if the command is vir
*@buffer: pointer
*@new_command: double pointer
*Return: 1 if successful 0 otherwise
*/
int checkVir(char *buffer, char **new_command)
{
	int v, w, gets;

	if (new_command[1] == NULL)
	{
		gets = customStrcmp(new_command[0], "Vir");
		if (gets == 0)
		{
			for (v = 0; environ[v] != NULL; v++)
			{
				for (w = 0; environ[v][w] != '\0'; w++)
				{
					putchar(environ[v][w]);
				}
				putchar('\n');
			}
			free(buffer);
			free(new_command);
			return (0);
		}
	}
	return (1);
}
/**
*exitHandler - exits the shell
*@buffer: pointer
*@new_command: double pointer
*Return: always 0
*/
int exitHandler(char *buffer, char **new_command)
{
	int gets;

	gets = customStrcmp(new_command[0], "exit");
	if (gets == 0)
	{
		free(buffer);
		if (new_command[1] != NULL)
		{
			exit(atoi(new_command[1]));
		}
		else
			exit(0);
	}
}
/**
*main - entry point
*Return: always 0
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *new_command[64];

	while (1)
	{
		printf("$ ");
		if (custom_getline(&buffer, &bufsize) == -1)
		{
			putchar('\n');
			break;
		}
		new_command[0] = customStrtok(buffer, "\n");

		if (new_command[0] != NULL)
		{
			int v = 1;

			while ((new_command[v] = customStrtok(NULL, "\n")) != NULL)
			{
				v++;
				new_command[v] = NULL;
			}
			if (checkVir(buffer, new_command) == 1)
				exitHandler(buffer, new_command);
		}
		free(buffer);
		return (0);
	}
}
