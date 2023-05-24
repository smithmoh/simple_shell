#include "main.h"
/**
 *main - entry point for the shell
 *@argc: argument count
 *@argv: argument vector
 *Return: Always 0
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *buffer = NULL;
	char **new_command;
	int v, countt = 0;
	char *lineptr = NULL;
	size_t n = 0;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, ":) ", 3);
			custom_getline(&lineptr, &n, stdin);
			countt++;

			if (!buffer)
			{
				continue;
				exitHandler(buffer, new_command);
				v = checkVir(buffer, new_command);

				if (v == 0 || new_command == 0)
					continue;
				fork_fa(buffer, new_command, argv, countt);
			}
		}
	}
	return (0);
}
