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
