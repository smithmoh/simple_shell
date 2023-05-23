#include "main.h"
/**
*free_p - frees a pointer
*@ptr: pointer
*Return: 1 if successful 0 if otherwise
*/
int free_p(void **ptr)
{
	if (ptr && *ptr)
	{
		free(ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
