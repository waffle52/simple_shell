#include "header.h"

/**
 * showenv - Function that prints the entire environmental
 * variable list onto the console
 * @environ: List of environmental variables, passed from main
 * Return: Nothing
 */
void showenv(char **environ)
{
	char newline = '\n';
	int count, length;

	for (count = 0; environ[count] != NULL; count++)
	{
		length = _strlen(environ[count]);
		write(STDOUT_FILENO, environ[count], length);
		write(STDOUT_FILENO, &newline, 1);
	}
}
