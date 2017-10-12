/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 05:34:28 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/12 11:51:43 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ft_putstr("invalid env option : ");
		ft_putendl(args[*i]);
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
