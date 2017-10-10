/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 08:27:16 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/10 13:56:53 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_var(char **env, char *var)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(var))
		return (-1);
	while (env[i])
	{
		tmp = ft_strcpy_until(env[i], '=');
		if (ft_strcmp(tmp, var) == 0)
		{
			free(tmp);
			return (i);
		}
		free(tmp);
		i++;
	}
	return (-1);
}

int			change_value(char **env, char *var, char *new_value)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		tmp = ft_strcpy_until(env[i], '=');
		if (ft_strcmp(tmp, var) == 0)
		{
			env[i] = ft_free(env[i]);
			tmp = ft_free(tmp);
			if (new_value != NULL)
				env[i] = ft_strjoin_separator(var, new_value, "=", 0);
			else
				env[i] = ft_strjoin_separator(var, "=", "", 0);
			return (1);
		}
		i++;
		tmp = ft_free(tmp);
	}
	return (0);
}

char		**rm_var_env(char **env, char *var)
{
	int		i;
	int		l;
	int		x;
	char	**new_env;

	i = 0;
	l = 0;
	x = check_var(env, var);
	if (x == -1)
		return (env);
	new_env = (char **)ft_memalloc(sizeof(char *) * 2);
	while (env[i])
	{
		if (i != x)
		{
			new_env = (char **)ft_realloc(new_env, sizeof(char *) * (l + 2),
										sizeof(char *) * (l + 1));
			new_env[l] = ft_strdup(env[i]);
			l++;
		}
		i++;
	}
	new_env[l] = NULL;
	env = free_doubletab(env);
	return (new_env);
}

char		**add_var_env(char **env, char *new_var, char *new_value)
{
	char	**new_env;
	int		size_env;

	if (check_var(env, new_var) != -1)
	{
		change_value(env, new_var, new_value);
		return (env);
	}
	size_env = ft_tablen(env);
	new_env = ft_realloc(env, sizeof(char *) * (2 + size_env),
						sizeof(char *) * (1 + size_env));
	if (new_value != NULL)
		new_env[size_env] = ft_strjoin_separator(new_var, new_value, "=", 0);
	else
		new_env[size_env] = ft_strjoin(new_var, "=");
	size_env++;
	new_env[size_env] = NULL;
	return (new_env);
}

char	**create_env()
{
	int			i;
	char		**env;
	extern char	**environ;

	i = 0;
	env = (char **)ft_memalloc(sizeof(char *) * 2);
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
