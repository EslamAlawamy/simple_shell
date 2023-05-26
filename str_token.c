#include "shell.h"
/**
 * string_token - handles the string
 * @str: the string
 * @delimiter: the split string
 * @argv: argument vector
 * Return: void
 */
void string_token(char *str, char *delimiter, char *argv[])
{
	char *first_ptr = NULL;
	char *second_ptr = NULL;
	int argc = 0;
	int len;

	if (str != NULL)
	{
		len = _strlen(str);
		while (len > 0 && str[len - 1] == ' ')
			str[--len] = '\0';
	}
	first_ptr = str;
	while (*first_ptr && *first_ptr == ' ')
		first_ptr++;

	second_ptr = first_ptr;

	while (*first_ptr != '\0')
	{
		if (_strcmp(first_ptr, delimiter) == 0)
		{
			*first_ptr = '\0';
			while (*(first_ptr + 1) == ' ')
				first_ptr++;
			argv[argc++] = second_ptr;
			second_ptr = first_ptr + 1;
			if (argc >= MAXARGS)
				break;
		}
		first_ptr++;
	}
	argv[argc++] = second_ptr;
	argv[argc] = NULL;
}
