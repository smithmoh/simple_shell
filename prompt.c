#include "main.h"

#define BUFFER_SIZE 1024

void displayPrompt(void)
{
	printf("cisgood$ ");
}

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
void runShell(void)
{
	char buffer[BUFFER_SIZE];
	char *new_command;

	while (1)
	{
		displayPrompt();
	}
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
int main(void)
{
	runShell();
	return (0);
}
