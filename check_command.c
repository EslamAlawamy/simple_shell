#include "shell.h"
/**
 * add_bin_prefix - function  adds path to command.
 * @argv:arguments vector
 * @new_arg: the full command
 * Return: void
 */
void add_bin_prefix(char *argv[], char *new_arg)
{
	char *prefix_path = "/bin/";
	size_t prefix_len;
	size_t arg_len;

	if (argv[0] == NULL)
		return;

	prefix_len = _strlen(prefix_path);
	arg_len = _strlen(argv[0]);

	if (_strcmp(argv[0], prefix_path) == 0 || _strcmp(argv[0], "./") == 0
			|| _strcmp(argv[0], "../") == 0)
		return;

	_strncpy(new_arg, prefix_path, prefix_len);
	_strncpy(new_arg + prefix_len, argv[0], arg_len);
	new_arg[prefix_len + arg_len] = '\0';

	argv[0] = new_arg;
}
