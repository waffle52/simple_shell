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
 * @d: Struct. For holding address to buffer for freeing later
 * Return: copied string or NULL if fail
 */
char *_strdup(char *str, struct data *d)
{
	if (str == NULL)
		return (NULL);

	d->buffer = malloc(sizeof(char *) * (_strlen(str) + 1));
	if (d->buffer == NULL)
		return (NULL);

	_strcpy(d->buffer, str);
	return (d->buffer);
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

/**
 * _strcmp - Entry point
 * @s1: value of char
 * @s2: value of char
 * Description: compares two strings)?
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i, m;

	i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
			m = s1[i] - s2[i];
		}
		else
		{
			m = s1[i] - s2[i];
			break;
		}
	}

	return (m);
}
