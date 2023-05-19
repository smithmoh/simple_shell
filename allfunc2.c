#include "main.h"
/**
*customStrdup - it duplicates the string
*@str: the string to be duplified
*Return: the duplicated string
*/
char *customStrdup(char *str)
{
	int length;
	char *ano_new;

	length = customStrlen(str);

	if (str == NULL)
	{
		return (0);
	}

	ano_new = (char *)malloc((length + 1) * sizeof(char));
	if (ano_new == NULL)
	{
		return (NULL);
	}
	customStrcpy(ano_new, str);
	return (ano_new);
}
/**
*freeTokens - it frees tokens
*@tokens: the tokens to be freed
*/
void freeTokens(char **tokens)
{
	int k;

	if (tokens == NULL)
	{
		return;
	}
	k = 0;
	for (k = 0; tokens[k] != NULL; k++)
	{
		free(tokens[k]);
	}
	free(tokens);
}
/**
*My_customStrchr - in the input string it finds c
*@s: the string to find c
*@c: the char to be found
*Return: the char found
*/
char *My_customStrchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
/**
*customStrncpy - copies a string up to a no of btytes
*@src: string to be copied
*@dest: the destination of the string to be copied
*@n: the number of bytes copied
*Return: a pointer to the destination
*/
char *customStrncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/**
*customStrchr - it locates a character in a string
*@s: the string containing the character
*@c: the character to be found
*Return: a character
*/
char *customStrchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
