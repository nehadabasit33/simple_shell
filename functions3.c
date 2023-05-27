#include "shell.h"
/**
  * _strdup - It duplicates the content on a string.
  * @str: The string the duplicate.
  * Return: A pointer to the duplicate string.
  */
char *_strdup(char *str)
{
	int len;
	char *back;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	back = malloc(sizeof(char) * (len + 1));
	if (!back)
		return (NULL);
	_strcpy(back, str);
	return (back);
}
/**
  * _strcpy - Copies the content of a pointer to another.
  * @src: The string to copy from.
  * @dest: The string to paste to.
  * Return: A pointer to the destination string.
  */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
	return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
  * _builtin - Checks for builtin commands.
  * @argv: Contains possible arguements.
  * @command: Input from user.
  * Return: -1 if exit and 0 if env.
  */
int _builtin(char **argv, char *command)
{
	int j;

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
		{
			j = _atoi(argv[1]);
			free(command);
			exit(j);
		}

		else
		{
			free(command);
			exit(0);
		}
	}

	if (_strcmp(argv[0], "env") == 0)
	{
		_printenv();
		return (1);
	}

	return (0);
}
/**
  * _strcat - Concatenates a string to the end of another.
  * @src: The string to concatenate.
  * @dest: The string to concatenate to.
  * Return: A pointer to the destination string.
  */
char *_strcat(char *dest, char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}
/**
  * _strtok - Tokenizes a string.
  * @str: The string to tokenize.
  * @del: The delimeter to watch out for.
  * Return: The tokenized string.
  */
char *_strtok(char *str, const char *del)
{
	static char *next;
	char *start = NULL;

	if (str != NULL)
	{
		next = str;
	}
	if (*next == '\0')
	{
		return (NULL);
	}
	while (*next != '\0' && *next == *del)
	{
		next++;
	}
	if (*next == '\0')
	{
		return (NULL);
	}
	start = next;
	while (*next != '\0')
	{
		if (*next == *del)
		{
			next++;
			if (*next == *del)
				*(next - 1) = '\0';

			while (*next == *del)
			{
				next++;
			}
			*(next - 1) = '\0';
			return (start);
		}
		next++;
	}
	return (start);
}
