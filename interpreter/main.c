#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*find_matching_bracket(char *code);

void	brainfuck(char *command, char *array)
{
	char	*pointer;
	int		brackets;

	pointer = array;
	while (*command != '\0')
	{
		if (*command == '>')
			pointer++;
		else if (*command == '<')
			pointer--;
		else if (*command == '+')
			(*pointer)++;
		else if (*command == '-')
			(*pointer)--;
		else if (*command == '[' && *pointer == 0)
			command = find_matching_bracket(command);
		else if (*command == ']' && *pointer != 0)
			command = find_matching_bracket(command);
		else if (*command == '.')
			putchar(*pointer);
		else if (*command == ',')
			*pointer = getchar();
		command++;
	}
}

char	*find_matching_bracket(char *code)
{
	int brackets = 0;

	if (*code == '[')
	{
		while (*code != '\0')
		{
			if (*code == '[')
				brackets++;
			else if (*code == ']')
				brackets--;

			if (brackets == 0)
				return (code);
			code++;
		}
		return (NULL);
	}
	else if (*code == ']')
	{
		while (*code != '\0')
		{
			if (*code == ']')
				brackets++;
			else if (*code == '[')
				brackets--;

			if (brackets == 0)
				return (code);
			code--;
		}
		return (NULL);
	}
}

int		main(int argc, char **argv)
{
	char	*array;

	if (argc != 2)
	{
		printf("Give one argument as code\n");
		return (0);
	}
	array = malloc(sizeof(char) * 30000);
	memset(array, 0, sizeof(array));
	brainfuck(argv[1], array);
	return (0);
}
