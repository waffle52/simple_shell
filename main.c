#include "header.h"

int main(int argc, char *argv[], char **env_cmd)
{
	char *command = NULL, *env_string = NULL, *commandcopy = NULL, *token;
	size_t command_size = 0, commandnum = 0, i = 0;
	char **array;
	char delim[] = " ";
	int status = 0, run = 0;
	pid_t pid;
	struct data mine;
	(void)argc, (void)argv;

	signal(SIGINT, SIG_IGN);
	env_string = _getenv("PATH", env_cmd);
	atty();

	while((run = getline(&command, &command_size, stdin)))
	{
		commandnum = 0;
		command_size = 0;

		if (run == EOF)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		for(i = 0; command[i]; i++)
		{
			if (command[i] == '\n')
				command[i] = '\0';
		}

		command = strtok(command, "#");
	        commandcopy = _strdup(command, &mine);

		token = strtok(commandcopy, delim);

		while(token != NULL)
		{
			token = strtok(NULL, delim);
			commandnum++;
		}

		array = malloc(sizeof(char *) * (commandnum + 1));

		token = strtok(command, delim);
		i = 0;
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		array[i] = NULL;

		if (array[0] != NULL && _strcmp("exit", array[0]) == 0)
		{

			if (array[1] != NULL)
			{
				if (*(array[1]) <= '9' && *(array[1]) >= '0')
					status = _atoi(array[1]);
			}
			freeAndFlush(command, commandcopy, array);
		        pid = fork();
			while(pid != 1)
			{
				_exit(status);
			}
		}

		if (array[0] != NULL && _strcmp("cd", array[0]) == 0)
		{
			our_cd (array[1], env_cmd);

		}

		if (array[0] != NULL && _strcmp("env", array[0]) == 0)
		{
			if (array[1] != NULL)
				showenv(array[1], env_cmd);
			else
				show_only_env(env_cmd);
		}

		if (array[0] != NULL)
		{
			mine.buffer = NULL;
			array[0] = static_path(array[0], env_string, &mine);

			free(mine.buffer);
			/* needed to free exact amount but stops program from working free(mine.token2); */
		}

		if (fork() == 0)
		{
			if ((execve(array[0], array, NULL) == -1))
				{
					write(STDERR_FILENO, array[0], _strlen(array[0]));
					write(STDERR_FILENO, ": command not found\n", 21);

				}
			exit(status);
		}
		else
			wait(NULL);

	        freeAndFlush(command, commandcopy, array);

		command = NULL;
		commandcopy = NULL;
		atty();
	}
        freeAll(&mine);
	return(0);
}

void atty(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

void freeAndFlush(char *command, char *commandcopy, char **array)
{
	free(command);
	free(commandcopy);
	free(array);
	fflush(stdin);
}
