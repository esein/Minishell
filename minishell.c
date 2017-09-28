/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:43:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/28 14:44:34 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_prompt(char **env)
{
	char	*pwd;
	struct utsname name;
	char	*tmp;

	pwd = NULL;
//	name = ft_memalloc(sizeof(name));
	uname(&name);
	pwd = getcwd(pwd, 0);
	tmp = ft_strcpy_until(name.nodename, '.');
	COLOR(S_CYAN);
	ft_putchar('[');
	ft_putstr(tmp);
	free(tmp);
	ft_putchar(':');
	tmp = ft_str_endcpy_until(pwd, '/');
	tmp = ft_strcut_begin(tmp, 1);
	ft_putstr(tmp);
	ft_putstr("]");
	COLOR(NONE);
	ft_putchar(' ');
//	free(name);
	free(pwd);
	free(tmp);
	return (0);
}

int		main()
{
	char	**env;

	env = create_env();
	execute(env);
//	free_doubletab(env);
	return (0);
}
