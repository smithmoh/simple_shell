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
	char **new_command;
	int p, v, countt = 0;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, ":) ", 3);
			buffer = custom_getline();
			count++;

			if (!buffer)
			{
				continue;
				p = calculate_word(buffer);
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
