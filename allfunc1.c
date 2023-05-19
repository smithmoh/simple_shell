#include "main.h"
/**
*customStrcmp - it compares two strings
*@s1: string 1 to be compared
*@s2: string 2 to be compared
*Return: a negative int if s2>s1
*0 if s2 == s1
*a positive int if s1>s2
*/
int customStrcmp(char *s1, char *s2)
{
	int w = 0;

	while (s1[w] == s2[w])
	{
		if (s1[w] == '\0')
		{
			return (0);
		}
		w++;
	}
	return (s1[w] - s2[w]);
}
/**
*customStrncmp - it compares the string up to no of bytes
*@s1: string 1 to be compared
*@s2: string 2 to be compared
*@n: the maximum no of chars to be compared
*Return: 0 if successful, +ve value if s1>s2
*-ve value if s2>s1
*/
int customStrncmp(char *s1, char *s2, int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 == '\0')
		{
			return (0);
		}
		s2++;
		s1++;
		n--;
	}
}
/**
*customStrcpy - it copies src to dest
*@dest: the destination to be copied to
*@src: the string to copy
*Return: a pointer to the destination
*/
char *customStrcpy(char *dest, char *src)
{
	char *pov = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (pov);
}
/**
*customStrlen - returns the length of the string
*@s: the string length to be checked
*Return: the length of the string
*/
int customStrlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
/**
*customStrcat - it concatenates the string pointed to by src
*@src: the string to be appended
*@dest: the string to be concatenated upon
*Return: a pointer to dest
*/
char *customStrcat(char *dest, char *src)
{
	char *uav = dest;

	while (*uav != '\0')
	{
		uav++;
	}
	while (*src != '\0')
	{
		*uav++ = *src++;
	}
	*uav = '\0';

	return (dest);
}
