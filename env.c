/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 08:27:16 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 11:40:17 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(char **env, char *var)
{
	int	i;
	char *tmp;

	i = 0;
	while (env[i] != 0)
	{
		tmp = ft_str_endcpy_until(env[i], '=');
		tmp = ft_str_endcut(tmp, 1);
		if (ft_strcmp(tmp, var) == 0)
		{
			free(tmp);
			tmp = ft_strcpy_until(env[i], '=');
			tmp = ft_strcut_begin(tmp, 1);
			return (tmp);
		}
		free(tmp);
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
