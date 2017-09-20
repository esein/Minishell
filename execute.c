/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 20:35:53 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/20 18:29:01 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_builtin(int	num, char **args)
{
	if (num == 1)
		ft_putstr("cd");
	else if (num == 2)
		echo(args);
	else if (num == 3)
		ft_putstr("env");
	else if (num == 4)
		ft_putstr("setenv");
	else if (num == 5)
		ft_putstr("unsetenv");
	else if (num == 6)
		exit(0);
	return (0);
}

int		run_bin(char **args, char **env, char *bin)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	else if (pid < 0)
		exit_error("fork error");
	else
	{
		execve(bin, args, env);
		free(bin);
	}
	return (0);
}

int		execute(char **env)
{
	char	*entry;
	int		end;
	int		num;
	char	**args;
	char	*bin;

	end = 0;
	entry = NULL;
	while (end == 0)
	{
		print_prompt(env);
		entry = read_entry();
		if (entry[0] != '\0')
		{
			args = parse_entry(entry);
			if ((num = check_builtin(args[0])) > 0)
				run_builtin(num, args);
			else if ((bin = find_bin(env, args[0])) != NULL)
				run_bin(args, env, bin);
			else
				free(bin);
			free_doubletab(args);
		}
	}
	return (0);
}
