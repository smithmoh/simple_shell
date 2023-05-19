#include "main.h"

int main(__attribute__((unused))int argc, char **argv)
{
	int i;
	char *new_command, *command_path;
	size_t bufsize;
	char **new_commands;

	bufsize = BUF_SIZE;
	new_command = (char *)malloc(bufsize * sizeof(char));
	if (new_command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
			fflush(stdout);
			new_command = read_line();
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			new_commands = handle_seperators(new_command);
			for (i = 0; new_commands[i] != NULL; i++)
			{
				argv = parse_line(new_commands[i]);
				if (_strcmp(argv[0], "exit") == 0)
				{
					if (argv[1] != NULL)
					{
						exit_handler(argv);
					}
					else
					{
						handle_exit(argv);
					}
				}
				else if (_strcmp(argv[0], "env") == 0)
				{
					handle_env(argv);
				}
				else if (_strcmp(argv[0], "cd") == 0)
				{
					change_directory(argv);
				}
				else
				{
					command_path = find_executable(argv);
					child_process(command_path, argv);
				}
				free(command_path);
			}
			free_tokens(new_commands);
		}
	}
	free(new_command);
	return (0);
}
