#include "header.h"
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int our_setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;
	size_t name_len, value_len;
	char *new_environ;

	if (name == NULL)
		return (-1);

	name_len = _strlen(name);
	if (name_len == 0)
		return (-1);

	for (i = 0; i <name_len; i++)
	{
		if (name[i] == '=')
			return (-1);
	}

	value_len = _strlen(value);
	new_environ = malloc(name_len + value_len + 2);
	if (new_environ == NULL)
		return (NULL);

	_memcpy(new_environr, name, name_len);
	new_environ[name_len] = '=';
	_memcpy(new_environ, name_len + 1, value, value_len);
	new_environ[name_len + value_len + 1] = NULL;

	return (0)

}
