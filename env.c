/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 08:27:16 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/08 21:30:39 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
