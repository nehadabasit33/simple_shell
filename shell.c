#include "shell.h"

/**
 *main - entry point
 *@ac: Argument count.
 *@av: Argument variable.
 *Return: 0 on success and 1 otherwise
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	int i = 0;
	char *command = NULL;
	size_t len;
	char *dir = NULL;
	char *argv[MAX_ARG];

	while (1)
	{
		if (getline(&command, &len, stdin) == -1)
		{
			perror(NULL);
			exit(1);
		}
		_parsecmd(command, argv);
		if (argv[0] != NULL)
		{
			ignore_stderr();
			i = _builtin(argv, command);

			if (i == 0)
			{
				command = _getpath(argv, dir);
				_process(argv, command, av);
			}

			if (dir != NULL)
				free(dir);
		}
		free(command);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_SUCCESS);
}
