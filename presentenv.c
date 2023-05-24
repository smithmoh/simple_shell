#include "main.h"
/**
*builtinEnv - builds the env
*Return: void
*/
void builtinEnv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
*runShell - runs the shell
*Return: void
*/
void runShell(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *new_command[64];
	int countt = 0;
	char *argv[64];

	while (1)
	{
		printf("$ ");

		if (custom_getline(&buffer, &bufsize, stdin) == -1)
		{
			putchar('\n');
			break;
		}
		new_command[0] = customStrtok(buffer, " \n");
		countt++;
		if (new_command[0] != NULL)
		{
			int v = 1;

			while ((new_command[v] = customStrtok(NULL, " \n")) != NULL)
			{
				v++;
				new_command[v] = NULL;
			}
		}
		if (customStrcmp(new_command[0], "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
		else if (customStrcmp(new_command[0], "env") == 0)
		{
			builtinEnv();
		}
		else
			fork_fa(buffer, new_command, argv, countt);
		free(buffer);
	}
}
