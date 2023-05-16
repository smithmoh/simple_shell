#include "shell.h"
/**
*signal - sets up a signal handler to handle SIGINT
*@SIGINT: the signal that is being handled
*@handle_sigint: function executed when the signal is recieved
*Return: 1 if successful and -1 if error
*/
int main(void)
{
	char *line;
	char **args;
	int status = 1;

	signal(SIGINT, handle_sigint) /*handles the ctrl + c signal */
		do{
			prompt();
			line = read_line();
			args = split_line(line);
			status = execute(args);
			free(line);
			free(args)'
		}
	while (status)
		exit_shell(status); /* exit shell with status */
	return (EXIT_SUCCESS);
}
void exit_shell(int status)
{
	exit(status); /* exit shell with status */
}
/**
*execute: takes an array of strings and checks if the first arg is
*the built-in-command exit
*@args: double pointer
*Return: 1 if successful and -1 if error
*/
int execute(chaar **args)
{
	/* checks for built-in-command */
	if (strcmp(args[0], "exit") = 0)
	{
		if (args[1] != NULL)
		{
			/* convert argument to integer */
			int status = atoi(args[1]);
			exit_shell(status);
		}
		else
			exit_shell(0);
	}
	else
	{
		pid_t pid;
		int status;
		pid = fork();

		if (pid == 0)
		{
			/* child process */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
			}
			exit(EXIT_FAILURE);
		}
		else
			if (pid < 0)
			{
				/* error forking */
				perror("Error");
			}
			else
				/* parent process */
				do{
					waitpid(pid, &status, WUNTRACED);
				}
		while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	return (1);
}
