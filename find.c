/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:37:19 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/12 11:47:59 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_name(char *wd, char *name)
{
	int				ret;
	DIR				*dir;
	struct dirent	*file;

	if ((dir = opendir(wd)) == NULL)
		return (0);
	while ((file = readdir(dir)))
		if (ft_strcmp(file->d_name, name) == 0)
		{
			closedir(dir);
			return (1);
		}
	closedir(dir);
	return (0);
}

char	*find_bin(char **env, char *name)
{
	char	**tmp;
	char	*tmp1;
	char	*join;
	int		i;

	i = 0;
	if (((tmp1 = check_path(name, env)) != NULL))
		return (tmp1);
	if ((tmp1 = get_value(env, "PATH")) == NULL)
		return (ft_strdup(name));
	tmp = ft_strsplit(tmp1, ':');
	tmp1 = ft_free(tmp1);
	while (tmp[i] != 0)
	{
		if (find_name(tmp[i], name) == 1)
		{
			join = ft_strjoin_separator(tmp[i], name, "/", 0);
			free_doubletab(tmp);
			return (join);
		}
		i++;
	}
	free_doubletab(tmp);
	return (ft_strdup(name));
}

char	*get_value(char **env, char *var)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i] != 0)
	{
		tmp = ft_strcpy_until(env[i], '=');
		if (ft_strcmp(tmp, var) == 0)
		{
			tmp = ft_free(tmp);
			tmp = ft_str_endcpy_until(env[i], '=');
			tmp = ft_strcut_begin(tmp, 1);
			return (tmp);
		}
		tmp = ft_free(tmp);
		i++;
	}
	return (NULL);
}
