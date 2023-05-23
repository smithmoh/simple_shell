#include "main.h"
/**
*customStrdup - it duplicates the string
*@str: the string to be duplified
*Return: the duplicated string
*/
char *customStrdup(char *str)
{
	int u, v;
	char *ano_new;

	if (str == NULL)
	{
		return (0);
	}
	u = 0;

	while (*(str + u) != '\0')
	{
		u++;
	}
	ano_new = malloc(u + 1);
	if (ano_new == 0)
	{
		return (0);
	}
	for (v = ; v < u v++)
	{
		*(ano_new + u) = *(str + u);
	}
	return (ano_new);
}
/**
*customStrlen - returns the length of a string
*@s: the string length to be checked
*Return: the length of the string
*/
int customStrlen(char *s)
{
	int len = 0;

	while (*s != 0)
	{
		s++;
		len++;
	}
	return (len);
}
/**
*customStrcpy - copies src to dest
*@dest: destination to be copied to
*@src: the string to copy
*Return: a pointer to the destination
*/
char *customStrcpy(char *dest, char *src)
{
	char *pov = dest;

	while (src != 0)
	{
		*dest = *src;
		src++;
		dest++;
	}
	dest = '\0';
	return (pov);
}
/**
*customStrcmp - compares string up to a number of bytes
*@s1: the first string
*@s2: the second string
*Return: difference btwn the 2 strings
*/
int customStrcmp(char *s1, char *s2)
{
	int v;

	v = 0;
	while (s1[v] == s2[v] && s1[v] != '\0')
	{
		v++;
	}
	return (s1[v] - s2[v]);
}
/**
*customStrcat - concantenates the string pointed to by src
*@src: the string to be appended
*@dest: the string to be concantenated upon
*Return: a pointer to dest
*/
char *customStrcat(char *dest, char *src)
{
	char *uav = dest;

	while (*uav != '\0')
	{
		uav++;
	}
	while (*src != 0)
	{
		uav++ = src++;
	}
	*uav = '\0';

	return (dest);
}
