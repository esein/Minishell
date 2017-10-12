/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:43:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/12 11:54:15 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**clone_env(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = (char **)ft_memalloc(sizeof(char *) * 2);
	while (env[i])
	{
		new_env = (char **)ft_realloc(new_env, sizeof(char *) * (i + 2),
				sizeof(char *) * (i + 1));
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

char	**create_env(void)
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
	return (env);
}

char	*print_prompt(char **env, char *tmp, char *pwd)
{
	COLOR(S_RED);
	ft_putchar('[');
	COLOR(S_BROWN);
	ft_putstr(tmp);
	tmp = ft_free(tmp);
	COLOR(S_RED);
	ft_putchar(':');
	COLOR(S_CYAN);
	if (ft_strcmp(pwd, "/") == 0)
		ft_putstr(pwd);
	else
	{
		tmp = ft_str_endcpy_until(pwd, '/');
		tmp = ft_strcut_begin(tmp, 1);
		ft_putstr(tmp);
	}
	COLOR(S_RED);
	ft_putstr("]");
	COLOR(NONE);
	ft_putchar(' ');
	return (tmp);
}

int		set_prompt(char **env)
{
	char			*pwd;
	struct utsname	name;
	char			*tmp;

	pwd = NULL;
	if (uname(&name) != 0 || !(pwd = getcwd(pwd, 0)))
		exit_error("Undetermined error at : set_prompt()");
	tmp = ft_strcpy_until(name.nodename, '.');
	tmp = print_prompt(env, tmp, pwd);
	free(pwd);
	free(tmp);
	return (0);
}

int		main(void)
{
	char	**env;

	env = create_env();
	run_loop(env);
	free_doubletab(env);
	return (0);
}
