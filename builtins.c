/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:55:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/12 11:45:04 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **args)
{
	int	i;

	i = 1;
	if (args[1])
	{
		if (ft_strcmp(args[1], "-n") != 0)
		{
			ft_print_char_tab(&(args[1]), ' ');
			ft_putchar('\n');
		}
		else
		{
			i = 2;
			while (args[i])
			{
				ft_putstr(args[i]);
				i++;
				if (args[i])
					ft_putchar(' ');
			}
		}
	}
}

int		cd_builtin(char **env, char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putendl("cd : Too many arguments");
		return (0);
	}
	else if (i == 1)
	{
		if (chdir(get_value(env, "HOME")) == 0)
			change_value(env, "PWD", "HOME");
		else
			ft_putendl("invalid HOME");
	}
	else
	{
		if (chdir(args[1]) == 0)
			change_value(env, "PWD", args[1]);
		else
			ft_putendl("cd : can't access this");
	}
	return (1);
}

int		env_builtin(char **env, char **args)
{
	int		i;
	char	**new_env;
	char	*bin;

	bin = NULL;
	new_env = clone_env(env);
	i = 1;
	new_env = env_builtin_options(new_env, args, &i);
	if (i == -1)
	{
		free_doubletab(new_env);
		return (0);
	}
	if (args[i])
	{
		if (check_rights(bin = find_bin(env, args[i])) != 0)
			run_bin(&(args[i]), new_env, bin);
		bin = ft_free(bin);
	}
	else
		ft_print_char_tab(new_env, '\n');
	free_doubletab(new_env);
	return (0);
}

char	**set_env(char **env, char **args)
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
	if (x == 1)
		ft_print_char_tab(env, '\n');
	else if (x == 2)
		env = add_var_env(env, args[1], NULL);
	else if (x == 3)
		env = add_var_env(env, args[1], args[2]);
	return (env);
}

char	**unset_env(char **env, char **args)
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
			env = rm_var_env(env, args[i]);
			i++;
		}
	}
	return (env);
}
