#include "main.h"
/**
* main - entry point of the program
* Return: Always 0
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *new_command[64];
	int countt = 0;

	while (1)
	{
		printf(":) ");
		if (custom_getline(&buffer, &bufsize, stdin) == -1)
		{
			putchar('\n');
			break;
		}
		new_command[0] = customStrtok(buffer, "\n");
		countt++;

		if (new_command != NULL)
		{
			int v = 1;

			while ((new_command[v] = customStrtok(NULL, "\n")) != NULL)
			{
				v++;
			}
			new_command[v] = NULL;
		}
		if (customStrcmp(new_command[0], "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
		free(buffer);
	}
	return (0);
}
