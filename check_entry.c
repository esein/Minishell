/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:25:08 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/23 08:40:47 by gcadiou          ###   ########.fr       */
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
		return (ft_strdup(name));
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

char	**read_entry(void)
{
	char	*entry;
	int		ret;
	int		i;
	char	**args;

	args = NULL;
	i = 0;
	entry = NULL;
	ret = get_next_line(0, &entry);
	if (ret <= 0)
		exit(0);
	while (entry[i])
	{
		if (!(ISSPACE(entry, i)))
		{
			args = parse_entry(entry);
			return (args);
		}
		i++;
	}
	return (NULL);
}

char	**parse_entry(char *entry)
{
	char	**args;

	args = ft_parsecmd(entry);
	if (args == NULL)
		ft_putendl_fd("error in command parsing", 2);
	return (args);
}

int		check_args_setenv(char *args)
{
	int		i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		if (args[i] == '=')
		{
			ft_putendl_fd("setenv : bad syntax", 2);
			return (0);
		}
		i++;
	}
	return (1);
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
