#include "header.h"
/**
 * _strcmp - Function that compares 2 strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if 0, negative integer, or positive integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 > *s2)
		return (*s1 - *s2);
	else
		return (*s1 - *s2);
}
