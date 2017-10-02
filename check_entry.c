/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:25:08 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/02 19:56:29 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char *name, char **env)
{
	char	*tmp;

	tmp = NULL;
	if (name[0] == '/')
			return (ft_strdup(name));
	else if (ft_strncmp(name, "./", 2) == 0 || ft_strncmp(name, "../", 3) == 0)
	{
		tmp = ft_strjoin_separator(getcwd(tmp, 0), name, "/", 1);
		return (tmp);
	}
	else if (name[0] == '~')
	{
		if (name[1] != '/')
			return (ft_strdup(name));
		tmp = ft_strdup(name);
		tmp = ft_strcut_begin(tmp, 2);
		tmp = ft_strjoin_separator(get_value(env, "HOME"), tmp, "/", 3);
		return (tmp);
	}
	else
		return (NULL);
}

char	*read_entry()
{
	char	*entry;
	int		ret;
	int		i;
	i = 0;
	entry = NULL;
	ret = get_next_line(0 , &entry);
	if (ret <= 0)
		exit(0);
	while (entry[i])
	{
		if (!(ISSPACE(entry, i)))
			return (entry);
		i++;
	}
	return (NULL);
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
