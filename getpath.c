#include "main.h"
/**
*getPath - gets the path of the file
*@new_command: command by the user
*Return: the pathe of the file
*/
char *getPath(char *new_command)
{
	int v, p;
	char *delim = ":=", *tokens, **folder, *buffer;
	char *file = NULL;

	v = 0;
	buffer = getenv("PATH");
	p = calculate_word2(buffer);
	folder = malloc(sizeof(char *) * p);

	if (folder == NULL)
	{
		perror("Error in Memory");
		return (NULL);
	}
	tokens = customStrtok(buffer, delim);
	v = 0;

	while (tokens)
	{
		folder[v] = tokens;
		tokens = customStrtok(NULL, delim);
		v++;
	}

	folder[v] = NULL;
	file = getDir(folder, new_command);
	v = 0;
	free(folder);
	return (file);
}
/**
*getDir - get the directory
*@folder: double pointer
*@new_command: command by user
*Return: always 0
*/
char *getDir(char **folder, char *new_command)
{
	int v = 0;
	char *aws;

	aws = malloc(sizeof(char) * 100);
	if (aws == NULL)
	{
		return (NULL);
	}
	while (folder[v])
	{
		DIR *f;
		struct dirent *fiy;

		f = opendir(folder[v]);
		if (f)
		{
			while ((fiy = readdir(f)) != NULL)
			{
				if (customStrcmp(fiy->d_name, new_command))
				{
					customStrcpy(aws, folder[v]);
					customStrcat(aws, "/");
					customStrcat(aws, fiy->d_name);
					closedir(f);
					return (aws);
				}
			}
			closedir(f);
			v++;
		}
	}
	free(aws);
	return (new_command);
}
/**
*getEnvironmentVariable - gets environment variable
*@s: string
*Return: environment
*/
char *getEnvironmentVariable(char *s)
{
	int v;
	char *current_path = NULL;
	char *final_path = NULL;
	char *cpen;

	v = 0;
	while (environ[v] != NULL)
	{
		cpen = customStrdup(environ[v]);
		if (cpen == NULL)
		{
			free(cpen);
			return (NULL);
		}
		current_path = customStrtok(cpen, "=");

		if (customStrcmp(current_path, s) == 0)
		{
			final_path = customStrStr(environ[v], "/");
		}
		v++;
		free(cpen);
	}
	return (final_path);
}
