/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 20:35:53 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/16 05:07:46 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_bin(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	else if (pid < 0)
		exit_error("fork error");
	else
	{
//		execve();
	}
	return (0);
}

int		execute(char **args)
{
	char	**env;

//	env = create_env();
//	ft_print_char_tab(args, '\n');
//	ft_print_char_tab(env, '\n');
	if (ft_strcmp(args[0], "exit") != 0)
		return (0);
	else
		return (1);
}
