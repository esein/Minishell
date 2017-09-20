/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:55:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/20 19:59:08 by gcadiou          ###   ########.fr       */
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

void		set_env(char **env, char **args)
{
}
