#include "main.h"
/**
* customMemset - fills a memory block with a specified value
* @s: pointer to memory
* @b: the byte to fill with
* @n: the no of bytes
* Return: Always 0
*/
char *customMemset(char *s, char b, unsigned int n)
{
	unsigned int v;
	char *ptr = s;

	for (v = 0; v < n; v++)
	{
		ptr[v] = b;
	}
	return (s);
}
/**
* ffree - frees a string
* @cv: string
* Return: void
*/
void ffree(char *cv)
{
	if (!cv)
	{
		return;
	}
	free(cv);
}
/**
* customRealloc - reallocates the memory block
* @ptr: pointer
  @oldsize: size of prev block
* @newSize: size of new block
* Return: pointer
*/
void *customRealloc(void *ptr, unsigned int oldsize, unsigned int newSize)
{
char *h;

if (!ptr)
{
	return (malloc(newSize));
}
if (!newSize)
{
	free(ptr);
	return (NULL);
}
if (newSize == oldsize)
{
	return (ptr);
}
h = malloc(newSize);
if (!h)
{
	return (NULL);
}
oldsize = oldsize < newSize ? oldsize : newSize;
while (oldsize--)
{
	h[oldsize] = ((char *)ptr)[oldsize];
}
free(ptr);
return (h);
}
