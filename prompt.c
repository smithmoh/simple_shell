#include "main.h"

#define BUFFER_SIZE 1024
/**
*displayPrompt - displays the prompt
*Return: void
*/
void displayPrompt(void)
{
	printf("cisgood$ ");
}
/**
*executeCommand - executes the commands
*@new_command: pointer
*Return: command
*/
void executeCommand(char *new_command)
{
	int status;

	if (new_command == NULL)
	{
		return;
	}

	status = system(new_command);

	if (status == -1)
	{
		fprintf(stderr, "Error Implementing Command: %s\n", new_command);
	}
}
/**
*runShell - runs the shell
*Return: void
*/
void runShell(void)
{
	char buffer[BUFFER_SIZE];
	char *new_command;

	while (1)
	{
		displayPrompt();

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			putchar('\n');
			break;
		}
		new_command = customStrtok(buffer, "\t\n");
		if (new_command != NULL)
		{
			if (customStrcmp(new_command, "exit") == 0)
			{
				return;
			}
			executeCommand(new_command);
		}
	}
}
