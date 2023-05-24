#include "main.h"
/**
*customStrStr - it searches for bytes in a string
*@stack: occurencd 1 of the char
*@needle: string
*Return: void
*/
char *customStrStr(char *stack, char *needle)
{
	int u;
	int w;
	int x;

	for (u = 0; stack[u] != '\0'; u++)
	{
		w = 0;
		x = u;
		while (stack[x] == needle[w] && needle[w] != '\0')
		{
			w++;
			x++;
		}
		if (needle[w] == '\0')
		{
			return (stack + u);
		}
	}
	return (0);
}
/**
*customItoa - converts an integer to a string
*@n: the number of integers
*Return: the number of integers
*/
char *customItoa(int n)
{
	unsigned int uvp;
	int div = 1, v = 0;
	char *str;

	str = malloc(sizeof(char) * 11);
	if (str == NULL)
	{
		return (NULL);
	}
	if (n < 0)
	{
		str[v++] = '-';
		uvp = n * -1;
	}
	else
	{
		uvp = n;

		while (uvp / div > 9)
		{
			div *= 10;
		}
		while (div != 0)
		{
			str[v] = (uvp / div) + '0';
			uvp %= div;
			div /= 10;
			v++;
		}
		str[v] = '\0';
	}
	return (str);
}
