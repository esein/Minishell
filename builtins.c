/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:55:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/10 00:12:51 by gcadiou          ###   ########.fr       */
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

void		env(char **env, char **args)
{
	int		i;
	char	**new_env;

	new_env = NULL;
	i = 1;
	while (args[i])
	{
		if (args[i][0] == '-')
		{
			if (args[i][1] == 'u')
			{
				i++;
				new_env = rm_var_env(env, args[i]);
			}
			else if (args[i][i] == 'i')
			{
				new_env = free_doubletab(env);
				new_env = (char **)ft_memalloc(sizeof(char *) * 1);
				new_env[0] = NULL;
			}
		}
	}
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
//				if (check_var(env, args[i]) != -1)
					env = rm_var_env(env, args[i]);
			i++;
		}
	}
	return (env);
}
