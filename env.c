/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 08:27:16 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/03 17:13:50 by gcadiou          ###   ########.fr       */
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
	char	*join2;
	int		i;

	i = 0;
	if ((tmp1 = check_path(name, env)) != NULL)
		return (tmp1);
	tmp1 = get_value(env, "PATH");
	tmp = ft_strsplit(tmp1, ':');
	tmp1 = ft_free(tmp1);
	while (tmp[i] != 0)
	{
		if (find_name(tmp[i], name) == 1)
		{
			tmp1 = ft_strjoin(tmp[i], "/");
			join2 = ft_strjoin(tmp1, name);
			ft_free(tmp1);
			free_doubletab(tmp);
			return (join2);
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
	return (0);
}

char	**create_env()
{
	int			i;
	char		**env;
	extern char	**environ;

	i = 0;
	if (!(env = (char **)malloc(sizeof(char *) * 2)))
		exit(1);
	while (environ[i] != 0)
	{
		env = (char **)ft_realloc(env, sizeof(char *) * (i + 2),
				sizeof(char *) * (i + 1));
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
//	ft_print_char_tab(env, '\n');
	return (env);
}
