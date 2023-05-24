#include "main.h"
/**
*custom_getline - validates the input
*@lineptr: double pointer
*@n: size of the string
*@stream: the file pointer
*Return: the buffer
*/
int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t capacity = *n;
	size_t length = 0;
	int c;
	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL)
	{
		capacity = 128;
		*lineptr = (char *)malloc(capacity * sizeof(char));
	}
	if (*lineptr == NULL)
	{
		return (-1);
	}
	*n = capacity;

	while ((c = fgetc(stream)) != EOF)
	{
		if (length >= capacity - 1)
		{
			capacity *= 2;
			temp = (char *)realloc(*lineptr, capacity * sizeof(char));
			
			if (temp == NULL)
			{
				return (-1);
			}
			*lineptr = temp;
			*n = capacity;
		}
		(*lineptr)[length] = '\0';
	}
	return length > 0 ? (int)length : -1;
}
/**
*main1 - entry point
*Return: void
*/
int main1(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	printf("$ ");

	if (custom_getline(&buffer, &bufsize, stdin) == -1)
	{
		putchar('\n');
		return (1);
	}
	printf("Line entered: %s\n", buffer);
	free(buffer);

	return (0);
}
