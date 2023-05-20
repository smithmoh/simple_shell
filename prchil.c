#include "main.h"
/**
*executeChildProcess - the command found in this file is executed
*@tokens: a symbol that breaks code down to small pieces
*@command_path: path to the executable file
*Return: always 0
*/
int executeChildProcess(char *command_path, char **tokens)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(command_path, tokens, environ);
		perror("execve failed");
		exit(1);
	}
	else 
	{
		waitpid(pid, &status, 0);
	}
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	return (-1);
}
