/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:55:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/08 21:30:39 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		echo(char **args)
{
	if (args[1])
	{
		if (ft_strcmp(args[1], "-n") != 0)
		{
			ft_print_char_tab(&(args[1]), ' ');
			ft_putchar('\n');
		}
		else
		{
			if (args[2])
				ft_print_char_tab(&(args[2]), ' ');
		}
	}
}

char		**add_var_env(char **env, char *new_var, char *new_value)
{
	char	**new_env;
	int		size_env;

	if (check_var(env, new_var))
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

char		**rm_var_env(char **env, char *var)
{
	int		i;
	int		l;
	int		x;
	char	**new_env;

	i = 0;
	l = 0;
	x = check_var(env, var);
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

int			check_var(char **env, char *var)
{
	int		i;
	char	*tmp;

	i = 0;
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
	return (0);
}

char		**set_env(char **env, char **args)
{
	int	x;

	x = 0;
	while (args[x])
		x++;
	if (x > 3)
	{
		ft_putendl("setenv : Too many arguments");
		return (env);
	}
	ft_putstr("nb args setenv : ");
	ft_putnbr(x);
	ft_putchar('\n');
	if (x == 1)
		ft_print_char_tab(env, '\n');
	else if (x == 2)
	{
			env = add_var_env(env, args[1], NULL);
	}
	else if (x == 3)
	{
			env = add_var_env(env, args[1], args[2]);
	}
	return (env);
}

char		**unset_env(char **env, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
	{
		ft_putendl("unsetenv : Too few arguments");
		return (env);
	}
	else
	{
		i = 1;
		while (args[i])
		{
			if (check_var(env, args[i]))
				env = rm_var_env(env, args[i]);
			i++;
		}
	}
	return (env);
}
