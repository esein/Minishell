/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 20:35:53 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 12:16:23 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_entry()
{
	char *entry;
	int		ret;

	entry = NULL;
	ret = get_next_line(0 , &entry);
	if (ret <= 0)
		exit(0);
	return (entry);
}

char	**parse_entry(char *entry)
{
	char	**args;

	args = ft_strsplit_whitespace(entry);
	if (ft_strcmp(args[0], "exit") == 0)
		exit(0);
	if (args == NULL)
		exit(1);
	return (args);
}

int		run_bin(char **args, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	else if (pid < 0)
		exit_error("fork error");
	else
	{
		execve("/bin/ls", args, env);
	}
	return (0);
}

int		execute(char **env)
{
	char	*entry;
	int		end;
	char	**args;

	end = 0;
	entry = NULL;
	while (end == 0)
	{
		print_prompt(env);
		entry = read_entry();
		if (entry[0] != '\0')
		{
			args = parse_entry(entry);
			run_bin(args, env);
			free_doubletab(args);
		}
	}
	return (0);
}
