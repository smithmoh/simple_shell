#include "main.h"
/**
*displayPrompt - displays the prompt for the user to
*key commands
*Return: void
*/
void displayPrompt(void)
{
	char *prompt = "$ ";

	write(1, prompt, customStrlen(prompt));
}
/**
*readLine - reads the input keyed by the user in prompt
*Return: void
*/
char *readLine(void)
{
	char *new_command;
	size_t v;
	ssize_t read;
	int id;

	new_command = NULL;
	v = 0;
	read = customGetline(&new_command, &v, stdin);
	if (read == -1)
	{
		perror("getline failed");
		exit(1);
	}
	id = read - 1;
	if (new_command[id] == '\n')
	{
		new_command[id] = '\0';
	}
	return (new_command);
}
