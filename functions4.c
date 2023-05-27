#include "shell.h"

/**
 * ignore_stderr-Ignore stderr output.
 * Return: Void.
 */

void ignore_stderr(void)
{
	int devnull_fd;
	int stderr_fd;
	int new_stderr_fd;

	devnull_fd = open("/dev/null", O_WRONLY);

	if (devnull_fd == -1)
	{
		return;
	}

	stderr_fd = 2;
	close(stderr_fd);

	new_stderr_fd = open("/dev/null", O_WRONLY);

	if (new_stderr_fd == -1)
	{
		close(devnull_fd);
		return;
	}

	if (new_stderr_fd != stderr_fd)
	{
		if (new_stderr_fd != devnull_fd)
		{
			close(new_stderr_fd);
		}
	}

	close(devnull_fd);
}

/**
 * _atoi - Converts ascii to integer.
 * @str: The string to convert.
 * Return: The converted string.
 */

int _atoi(char *str)
{
	int i = 0;
	int j = 0;
	int k = 1;

	i = _strlen(str);
	i--;

	while (i >= 0)
	{
		j = j + ((str[i] - '0') * k);
		k = k * 10;
		i--;
	}

	return (j);
}
