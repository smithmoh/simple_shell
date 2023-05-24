#include "main.h"
/**
*main - entry point for the shell
*@argc: argument count
*@argv: argument vector
*Return: always 0
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *buffer = NULL;
	char **new_command = NULL;
	int v, countt = 0;
	size_t n = 0;
	int p = 0;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, ":) ", 3);
		}
		buffer = custom_getline(&buffer, &n, stdin);
		countt++;

		if (!buffer)
		{
			continue;
		}

		p = calculate_word(buffer);
		new_command = malloc(sizeof(char *) * p);
		if (new_command == NULL)
		{
			free(buffer);
			continue;
		}
		exitHandler(buffer, new_command);
		v = checkVir(buffer, new_command);

		if (v == 0 || new_command == 0)
		{
			free(buffer);
			free(new_command);
			continue;
		}
		fork_fa(buffer, new_command, argv, countt);
	}
	return (0);
}
