#include "main.h"
/**
*parseLine - goes through the line and its commands
*@command: the command to be parsed
*Return: a command pointer
*/
char **parseLine(char *new_command)
{
	int index;
	int tokenSize;
	char **tokens;
	char *tokenPointer;
	char *commandN;
	tokenise str;

	tokenSize = TOKEN_BUFSIZE;
	commandN = customStrdup(new_command);
	if (commandN == NULL)
		return (NULL);
	tokens = malloc(tokenSize * sizeof(char));
	if (tokens == NULL)
	{
		free(commandN);
		return (NULL);
	}
	tokenPointer = _customStrtok(&str, commandN, TOKEN_SEPERATOR);
	index = 0;
	while (tokenPointer != NULL)
	{
		tokens[index] = customStrdup(tokenPointer);
		if (tokens[index] == NULL)
		{
			freeTokens(tokens);
			free(commandN);
			return (NULL);
		}
		index++;
		tokenPointer = _customStrtok(&str, NULL, TOKEN_SEPERATOR);
	}
	tokens[index] = NULL;
	free(commandN);
	return (tokens);
}
