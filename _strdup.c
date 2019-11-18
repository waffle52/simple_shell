#include <stdio.h>
#include <stdlib.h>
#include "header.h"
/**
 * _strlen - Return the length of a string
 * @s: string
 * Return: string length i
 */
int _strlen(char *s)
{
	int slen = 0;

	while (*s)
	{
		slen++;
		s++;
	}
	return (slen);
}
/**
 * _strcpy - copy a string to a new destination
 * @dest: destination of copied string
 * @src: string to copy
 * Return: Pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}
/**
 * _strdup - duplicates as string
 * @str: string to duplicate
 * Return: copied string or NULL if fail
 */
char *_strdup(char *str)
{
	char *buffer;

	if (str == NULL)
		return (NULL);

	buffer = malloc(_strlen(str) + 1);
	if (buffer == NULL)
		return (NULL);

	_strcpy(buffer, str);
	return (buffer);
}
