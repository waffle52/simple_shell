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

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: integers, 0 if none
 */

int _atoi(char *s)
{
	unsigned int value = 0;
	int sign = 1;

	do {
		if (*s == '-')
		{
			sign = -sign;
		}
		else if ((*s >= '0' && *s <= '9') && *s != 0)
		{
			value *= 10;
			value += (*s - '0');
		}
		else if (value > 0)
		{
			break;
		}
	} while (*s++);

	return (value * sign);
}

/** will be add to second helper function later
 *void sigintHandler(int sig_num)
 *{
 *	resets handler so signal can be called again
 *	signal(SIGINT, sigintHandler);
 *	fflush(stdout);
 *}
 */
