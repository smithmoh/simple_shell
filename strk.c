#include "main.h"
/**
*tokeniseStr - sets the last token to null
*@str: token initializer
*Return: always 0
*/
void tokeniseStr(tokenise *str)
{
	str->last_token = NULL;
}
/**
*_customStrtok - finds the next token from the string input
*@str: pointer
*@string: string to be tokenised
*@delimiter: seperator
*Return: retrieved token
*/
char *_customStrtok(tokenise *str, char *string, const char *delimiter)
{
	char *firstToken;
	char *lastToken;

	if (string != NULL)
	{
		str->last_token = string;
	}
	if (string == NULL && str->last_token == NULL)
	{
		return (NULL);
	}
	firstToken = str->last_token;
	if (*firstToken == '\0')
	{
		str->last_token = NULL;
		return (NULL);
	}
	lastToken = firstToken;
	while (*lastToken != '\0' && My_customStrchr(delimiter, *lastToken) == NULL)
	{
		lastToken++;
	}
	if (*lastToken == '\0')
	{
		str->last_token = NULL;
	}
	else
	{
		*lastToken = '\0';
		str->last_token = lastToken + 1;
	}
	return (firstToken);
}
