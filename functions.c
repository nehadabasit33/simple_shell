#include "shell.h"

/**
 *  _strcspn - determines the length of initial segment of string before.
 *	an unwanted character.
 *  @str: The input string to check.
 *  @stop: The string that if found, stops the count.
 *  Return: The length of the initial segment.
 */

int _strcspn(char *str, char *stop)
{
	int i = 0;

	while (str[i] != *stop)
	{
		i++;
	}

	return (i);
}

/**
 * _parsecmd - It seperates the command arguement and stores them.
 * @command: The input command to parse.
 * @argv: The command arguements.
 */

void _parsecmd(char *command, char **argv)
{
	char *token;
	int argc = 0;
	char del[] = " ";

	command[_strcspn(command, "\n")] = '\0';
	token = _strtok(command, " ");

	while ((token) && (argc < MAX_ARG - 1))
	{
		if (*token == '#')
			break;

		argv[argc] = token;
		token = _strtok(NULL, del);
		argc++;
	}
	argv[argc] = NULL;
}


/**
 * _putchar - Prints a single character.
 * @c: Character to print.
 * Return: The character ascii equivalent.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Determines the length of string.
 * @str: The input string.
 * Return: The length of input string.
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}

	return (i);
}

/**
 * _strncmp - Compares two strings upto a certain length.
 * @str1: First input string.
 * @str2: Second input string.
 * @len: Number of characters to compare.
 * Return: 0 if they are same and 1 otherwise.
 */

int _strncmp(char *str1, char *str2, int len)
{
	int i = 0;

	while (i < len)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}

		else
		{
			i++;
		}
	}

	return (0);
}
