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
	int p, v, count = 0;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, ":) ", 3);
			buffer = custom_getline(char **lineptr, size_t *n, FILE *stream);
			count++;

			if (!buffer)
			{
				continue;
				p = calculate_word(buffer);
				exitHandler(buffer, new_command);
				v = checkVir(buffer, new_command);

				if (v == 0 || new_command == 0)
					continue;
				fork_fa(buffer, new_command, argv, count);
			}
		}
	}
	return (0);
}
