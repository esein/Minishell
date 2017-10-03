/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:23:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/03 17:21:50 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_rights(char *path_name)
{
	if (access(path_name, F_OK) < 0)
	{
		ft_putstr(path_name);
		ft_putstr(": ");
		ft_putendl("command not found");
		return (0);
	}
		return (1);
}

int		check_directory(char *path_name)
{
	DIR				*dir;
	struct dirent	*file;

	if ((dir = opendir(path_name)) == NULL)
	{
		ft_putstr(path_name);
		ft_putendl(": permission denied");
		return (1);
	}
	if ((file = readdir(dir)))
	{
		if (file->d_type == 4)
		{
			ft_putstr(path_name);
			ft_putendl(" is a directory");
			free(dir);
			return (1);
		}
	}
	free(dir);
	return (0);
}
