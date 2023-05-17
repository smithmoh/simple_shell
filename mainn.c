#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
*read_line - read a line from standard input
*@buffer: stores the input line
*@size: maximum input of the input line
*Return: the no of chars read of -1 on failure
*/
ssize_t read_line(char *buffer, size_t size)
{
	ssize_t num_read;

	num_read = read(STDIN_FILENO, buffer, size);
	if (num_read == -1)
	{
		perror("read");
		return (-1);
	}
	return (num_read);
}
/**
*execute_command - executes a command
*@command: the command to execute
*Return: 1 if successfully executed and 0 if failure
*/
int execute_command(const char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		/* forking failed */
		perror("fork");
		return (0);
	}
	else if (pid == 0)
	{
		/* child process */
	char *args[] = {command, NULL};

		if (execve(command, args, NULL) == -1)
		{
			/* executable not found */
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* parent process */
		int status;
		waitpid(pid, &status, 0);
	}
	return (1);
}
int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t num_read;

	while (1)
	{
		/* display prompt */
		write(STDOUT_FILENO, "$ ", 2);
		/* read the command */
		num_read = read_line(buffer, BUFFER_SIZE);

		if (num_read == -1)
		{
			continue;
		}
		else if (num_read == 0)
		{
			break;
		}
		if (buffer[num_read - 1] == '\n')
		{
			buffer[num_read - 1] = '\0';
		}
		if (!execute_command(buffer))
		{
			write(STDERR_FILENO, "Command not found\n", 18);
		}
	}
	return (EXIT_SUCCESS);
}
