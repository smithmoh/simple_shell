#include "main.h"
/**
*customMemset - fills a memory block with a specified value
*@s: pointer to memory
*@b: the byte to fill with
*@n: the no of bytes
*Return: always 0
*/
char *customMemset(char *s, char b, unsigned int n)
{
	unsigned int v;

	for (v = 0; v < n; v++)
	{
		s[v] = b;
	}
	return (s);
}
/**
*ffree - frees a string
*@cv: string
*Return: void
*/
void ffree(char *cv)
{
	char **c = cv;

	if (!cv)
	{
		return;
	}
	while (*cv)
	{
		free(*cv++);
		free(c);
	}
}
/**
*customRealloc - reallocates the memory block
*@ptr: pointer
*@oldSize: size of prev block
*@newSize: size of new block
*Return: pointer
*/
void customRealloc(void *ptr, unsigned int oldSize, unsigned int newSize)
{
	char *h

	if (!ptr)
	{
		return (malloc(newSize));
	}
	if (!newSize)
	{
		return (free(ptr, NULL));

		if (newSize == oldSize)
		{
			return (ptr);
		}
		h = malloc(newSize);
		if (!h)
		{
			return (NULL);
		}
		oldSize = oldSize < newSize ? oldSize : newSize;
		while (oldSize--)
		{
			h[oldSize] = ((char *)ptr)[oldSize];
			free(ptr);
		}
		return (h);
	}
}
