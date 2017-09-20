/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:25:08 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/20 10:59:14 by gcadiou          ###   ########.fr       */
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

int		check_builtin(char *name)
{
	if (ft_strcmp(name, "cd") == 0)
		return (1);
	else if (ft_strcmp(name, "echo") == 0)
		return (2);
	else if (ft_strcmp(name, "env") == 0)
		return (3);
	else if (ft_strcmp(name, "setenv") == 0)
		return (4);
	else if (ft_strcmp(name, "unsetenv") == 0)
		return (5);
	else if (ft_strcmp(name, "exit") == 0)
		return (6);
	else
		return (0);
}
