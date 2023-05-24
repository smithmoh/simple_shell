#include "main.h"
/**
*custom_getline - validates the input
*void: input parameter
*Return: the buffer
*/
char *my_custom_getline(void)
{
	char *buffer = NULL;
	size_t size;
	ssize_t vice;
	int v = 0;

	vice = custom_getline(&buffer, &size, stdin);
	if (!buffer)
	{
		perror("Error in Memory Buffer");
		return (NULL);
	}
	if (vice == 1)
	{
		free(buffer);
		return (NULL);
	}
	else if (vice == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(0);
		}
	}
	else
	{
		while (buffer[v] == ' ' && buffer[v + 1] == ' ')
		{
			v++;
		}
		if (buffer[v + 1] == '\n')
		{
			free(buffer);
			return (NULL);
		}
	}
	return (buffer);
}
/**
*handle_signal - handles the signal
*@sign: the signal
*/
void handle_signal(int sign)
{
	(void) sign;
	write(STDOUT_FILENO, "\n:) ", 3);
}
