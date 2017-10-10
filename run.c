/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:10:25 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/10 11:51:16 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_builtin(int	num, char ***env, char **args)
{
	if (num == 1)
		ft_putstr("cd");
	else if (num == 2)
		echo(args);
	else if (num == 3)
		built_env(*env, args);
	else if (num == 4)
		*env = set_env(*env, args);
	else if (num == 5)
		*env = unset_env(*env, args);
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
//		ft_putstr(args[0]);
//		ft_putstr(bin);
		execve(bin, args, env);
		if (check_directory(bin) == 0)
		{
			ft_putstr(bin);
			ft_putstr(": ");
			ft_putendl("command isn't executable");
		}
		exit(0);
	}
	return (0);
}

int		run_loop(char **env)
{
	char	*entry;
	int		end;
	int		num;
	char	**args;
	char	*bin;

	end = 0;
	entry = NULL;
	bin = NULL;
	while (end == 0)
	{
		print_prompt(env);
		entry = read_entry();
		if (entry != NULL)
		{
			args = parse_entry(entry);
			if ((num = check_builtin(args[0])) > 0)
				run_builtin(num, &env, args);
			else if (check_rights(bin = find_bin(env, args[0])) != 0)
				run_bin(args, env, bin);
			bin = ft_free(bin);
			free_doubletab(args);
		}
	}
	return (0);
}
