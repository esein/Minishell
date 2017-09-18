/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:43:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 12:14:20 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_prompt(char **env)
{
	char	*pwd;

	pwd = get_value(env, "PWD");
	ft_putstr(pwd);
	ft_putstr(">");
	free(pwd);
	return (0);
}

int		main()
{
	char	**env;

	env = create_env();
	execute(env);
	free_doubletab(env);
	return (0);
}
