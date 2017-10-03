/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:55:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/03 19:05:12 by gcadiou          ###   ########.fr       */
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

int			check_set(char **env, char **args)
{
	int	x;

	x=0;
	while (args[x])
		x++;
	if (x > 3)
	{
		ft_putstr("setenv : too many arguments");
		return (0);
	}
	ft_putstr("nb args setenv : ");
	ft_putnbr(x);
	return (1);
}

void		set_env(char **env, char **args)
{
	if (check_set(env, args) == 0)
		return (0);
}
