#include "main.h"

int main(__attribute__((unused))int argc, char **argv)
{
	int i;
	char *new_command, *command_path;
	size_t bufsize;
	char **new_commands;

	bufsize = BUF_SIZE;
	new_command = (char *)malloc(bufsize * sizeof(char));
	if (new_command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			displayPrompt();
			fflush(stdout);
			new_command = readLine();
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			new_commands = handleSeperators(new_command);
			for (i = 0; new_commands[i] != NULL; i++)
			{
				argv = parseLine(new_commands[i]);
				if (customStrcmp(argv[0], "exit") == 0)
				{
					if (argv[1] != NULL)
					{
						exitHandler(argv);
					}
					else
					{
						handleExit(argv);
					}
				}
				else if (customStrcmp(argv[0], "env") == 0)
				{
					handleEnvironment(argv);
				}
				else if (customStrcmp(argv[0], "cd") == 0)
				{
					changeDirectory(argv);
				}
				else
				{
					command_path = findExecutable(argv);
					executeChildProcess(command_path, argv);
				}
				free(command_path);
			}
			freeTokens(new_commands);
		}
	}
	free(new_command);
	return (0);
}
