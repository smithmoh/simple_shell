#include "main.h"
/**
*fork_fa - splits the directory
*@new_command: double pointer
*@buffer: pointer
*@argv: argument vector
*@countt: iterator
*Return: always 0
*/
void fork_fa(char *buffer, char **new_command, char **argv, int countt)
{
	int c;
	int status;
	pid_t pid;
	struct stat st;
	char str[10];

	sprintf(str, "%d", countt);
	if (new_command[0] != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			free(buffer);
			free(new_command);
			exit(-1);
		}
		if (pid == 0)
		{
			c = stat(new_command[0], &st);
			if (c != 0)
			{
				new_command[0] = getPath(new_command[0]);
				if (execve(new_command[0], new_command, NULL) == -1)
				{
					_perror(argv[0], str, new_command[0]);
					free(buffer);
					free(new_command);
					exit(-1);
				}
			}
			else if (pid > 0)
			{
				wait(&status);
			}
		}
	}
	free(buffer);
	free(new_command);
}
/**
*_perror - prints an error message
*@argv: argument vector
*@str: string
*@new_command: the input user command
*Return: always 0
*/
int *_perror(char *argv, char *str, char *new_command)
{
	write(STDERR_FILENO, argv, customStrlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, customStrlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, new_command, customStrlen(new_command));
	write(STDERR_FILENO, ": not found\n", 12);
	return (0);
}
