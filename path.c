#include "main.h"
/**
*customStrtok - splits string to small tokens
*@buffer: pointer to a char
*@p: integer
*Return: always 0
*/
char **my_customStrtok(char *buffer, char *delim)
{
	char **new_command;
	size_t v;
	char **uv;

	new_command = malloc(sizeof(char *) * (calculate_word(buffer) + 1));
	if (new_command == NULL)
	{
		free(buffer);
		return (NULL);
	}
	uv = my_customStrtok(buffer, delim);

	while (uv != NULL)
	{
		new_command[v] = *uv;
		uv = my_customStrtok(NULL, delim);
		v++;
	}
	new_command[v] = NULL;
	return (new_command);
}
/**
*calculate_word - checks buffer
*@buffer: the buffer
*Return: the total count
*/
int calculate_word(char *buffer)
{
	int v, countt = 1;
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
	int v, countt = 1;
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
