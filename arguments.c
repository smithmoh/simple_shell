#include "shell.h"
/**
*signal_handler - sets up a signal handler to handle sig
*@sig: the signal that is being handled
*Return: 1 if successful and -1 if error
*/
void signal_handler(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$", 3);
}
/**
*main - Entry point
*Return: EXIT_SUCCESS on success EXIT_FAILURE on failure
*/
int main(void)
{
	char *line;
	char **args;
	int status = 1;

	signal(SIGINT, signal_handler); /* handles the ctrl + c signal */

	do {
		prompt();
		line = read_line();
		args = split_line(line);
		status = execute(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
/**
*exit_shell - exits the shell with status
*@status: the exit status
*/
void exit_shell(int status)
{
	exit(status); /* exits shell with status */
}
/**
*execute - takes an array of strings and checks if the first arg is
*the built-in-command exit
*@args: double pointer
*Return: 1 if successful and -1 if error
*/
int execute(char **args)
{
	/* checks for built-in-command */
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			/* convert argument to integer */
			int status = atoi(args[1]);

			exit_shell(status);
		} else
			exit_shell(0);
	} else
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
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	return (1);
}
