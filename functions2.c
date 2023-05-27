#include "shell.h"
/**
  * _getenv - Retrieves the environment variable of an input string.
  * @name: The string whose environment variable to retrieve.
  * Return: Returns environment variable on success and NULL otherwise.
  */
char *_getenv(char *name)
{
	int i = 0;
	int len;

	if ((name == NULL) || (environ == NULL))
	{
		return (NULL);
	}
	len = _strlen(name);
	while (environ[i])
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			return (&environ[i][len + 1]);
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}
/**
  * _strcmp - Compares two strings.
  * @str1: First input string.
  * @str2: Second input string.
  * Return: 0 if they are same and 1 otherwise.
  */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while ((str1[i] && str2[i]) && (str1[i] == str2[i]))
	{
		i++;
	}
	if (str1[i] == str2[i])
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
/**
  * _printenv - It prints the environment.
  * Return: Void.
  */
void _printenv(void)
{
	int i = 0;
	int j = 0;
	char *line;

	while (environ[i])
	{
		line = environ[i];
		while (line[j])
		{
			_putchar(line[j]);
			j++;
		}
		_putchar('\n');
		i++;
		j = 0;
	}
}
/**
  * _getpath - Finds the path of the input command.
  * @argv: The argument variables.
  * @dir: The pointer to hold our path.
  * Return: 0 on success and 1 or -1 otherwise
  */
char *_getpath(char **argv, char *dir)
{
	char *variable_name = "PATH";
	char *value;
	char *valuetemp = NULL;
	char del[] = ":";
	char *token;
	struct stat st;
	char *tmp = NULL;

	tmp = argv[0];
	if (stat(tmp, &st) == 0)
	{
		return (tmp);
	}
	value = _getenv(variable_name);
	if (value)
	{
		valuetemp = _strdup(value);
		token = _strtok(valuetemp, del);
		while (token)
		{
			dir = malloc(_strlen(token) + _strlen(tmp) + 2);
			_strcpy(dir, token);
			_strcat(dir, "/");
			_strcat(dir, tmp);
			if (stat(dir, &st) == 0)
			{
				free(valuetemp);
				return (dir);
			}
			else
			{
				free(dir);
				token = _strtok(NULL, del);
			}
		}
		free(valuetemp);
	}
	return (argv[0]);
}

/**
  * _process - Creates the child process and executes the command.
  * @argv: Array of potential arguments variable.
  * @av: Argument variable.
  * @command: The input from user
  * Return: 0 on success and 1 otherwise.
  */
int _process(char **argv, char *command, char **av)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(NULL);
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror(av[0]);
			return (1);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			return (1);
		}

	}

	return (0);
}
