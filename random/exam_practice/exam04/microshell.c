#include "microshell.h"

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	cd(char **arv, int i)
{
	if (i != 2)
		return (err("cd error\n"));
	else if (chdir(arv[1]) == -1)
		return (err("Error: cannot change directory to "), err(arv[1]), err("\n"));
	return (0);
}

int	exec(char **arv, char **envp, int i)
{
	int	fd[2];
	int	status;
	int	has_pipe = arv[i] && !strcmp(arv[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return (err("error: piping error\n"));
	int	pid = fork();
	if (!pid)
	{
		arv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (err("error: redirection error\n"));
		execve(*arv, arv, envp);
		return (err("error: failed to execute "), err(*arv), err("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (err("error: redirection error\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = exec(argv, envp, i);
		}
	}
	return (status);
}
