#include "main.h"
/**
*customStrtok - splits string to small tokens
*@buffer: pointer to a char
*@p: integer
*Return: always 0
*/
char **customStrtok(char *buffer, int p)
{
	char **new_command;
	size_t v;
	char *uv;
	char *delim = " \n\t";

	new_command = malloc(sizeof(char *) * p);
	if (new_command == NULL)
	{
		free(buffer);
		return (NULL);
	}
	uv = customStrtok(buffer, delim);
	v = 0;

	while (uv)
	{
		new_command[v] = uv;
		uv = customStrtok(NULL, delim);
		v++;
	}
	new_command[v] = NULL;
	return (command);
}
/**
*calculate_word - checks buffer
*@buffer: the buffer
*Return: the total count
*/
int calculate_word(char *buffer)
{
	int v, countt = 2;
	char *delim = " ";

	for (v = 0; buffer[v] != '\0'; v++)
	{
		if (buffer[v] == delim[0])
		{
			countt++;
		}
	}
	return (countt);
}
/**
*calculate_word2 - checks buffer
*@buffer: the buffer
*Return: number
*/
int calculate_word2(char *buffer)
{
	int v, countt = 2;
	char *delim = ":";

	for (v = 0; buffer[v] != '\0'; v++)
	{
		if (buffer[v] == delim[0])
		{
			countt++;
		}
	}
	return (countt);
}
