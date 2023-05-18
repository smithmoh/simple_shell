#include "main.h"

int main(__attirbute__((unused))int argc, char **argv)
{
	int i;
	char *new_command, new_command_path;
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
			display_prompt();
			fflush(stdout);
			new_command = read_input();
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			new_commands = seperate_commands(new_command);
			for (i = 0; new_commands[i] != NULL; i++)
			{
				argv = parse_input(new_commands[i]);
				if (_strcmp(argv[0], "exit") == 0)
				{
					if (argv[1] != NULL)
					{
						exit_input_handler(argv);
					}
					else
					{
						handle_exit_input(argv);
					}
				}
				else if (_strcmp(argv[0], "env") == 0)
				{
					handle_env_input(argv);
				}
				else if (_strcmp(argv[0], "cd") == 0)
				{
					change_dir_input(argv);
				}
				else
				{
					new_command_path = get_executable(argv);
					child_process_input(new_command_path, argv);
				}
				free(new_command_path);
			}
			free_tokens(new_commands);
		}
	}
	free(new_command);
	return (0);
}
