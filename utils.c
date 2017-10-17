/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 05:34:28 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/17 09:45:35 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			change_pwd(char **env, char *value)
{
	char	*tmp;
	char	*pwd;

	pwd = NULL;
	tmp = NULL;
	if (chdir(value) != 0)
		return (-1);
	pwd = getcwd(pwd, 0);
	tmp = get_value(env, "PWD");
	change_value(env, "OLDPWD", tmp);
	change_value(env, "PWD", pwd);
	ft_free(tmp);
	ft_free(pwd);
	return (0);
}

void		exit_builtin(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		exit(0);
	else if (i == 2)
	{
		i = 0;
		while (args[1][i])
		{
			if (!ft_isdigit(args[1][i]))
			{
				ft_putendl_fd("exit : non numeric argument", 2);
				exit(1);
			}
			i++;
		}
		exit(ft_atoi(args[1]));
	}
	else
		ft_putendl_fd("exit : Too many arguments", 2);
}

int			env_builtin_norme(char ***env, char **args, int *i)
{
	if (args[*i][1] == 'u')
	{
		(*i)++;
		if (args[*i])
		{
			if (!(args[*i][0] == '-' || ft_strchr(args[*i], '=')))
				*env = rm_var_env(*env, args[*i]);
		}
		else
			(*i)--;
	}
	else if (args[*i][1] == 'i')
		*env = rm_all_env(*env);
	else
	{
		ft_putstr_fd("invalid env option : ", 2);
		ft_putendl_fd(args[*i], 2);
		*i = -1;
		return (0);
	}
	return (1);
}

char		**env_builtin_options(char **env, char **args, int *i)
{
	char	*tmp;

	tmp = NULL;
	while (args[*i])
	{
		if (args[*i][0] == '-')
		{
			if (env_builtin_norme(&env, args, i) == 0)
				return (env);
		}
		else if (ft_strchr(args[*i], '=') != 0)
		{
			tmp = ft_strcpy_until(args[*i], '=');
			env = add_var_env(env, tmp, &((ft_strchr(args[*i], '='))[1]));
			tmp = ft_free(tmp);
		}
		else
			break ;
		(*i)++;
	}
	return (env);
}

void		exit_error(char *msg)
{
	ft_putstr(msg);
	exit(1);
}
