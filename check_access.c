/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:23:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/13 22:46:34 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_rights(char *path_name)
{
	if (access(path_name, F_OK) < 0)
	{
		ft_putstr_fd(path_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("command not found", 2);
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
		ft_putstr_fd(path_name, 2);
		ft_putendl_fd(": permission denied", 2);
		return (1);
	}
	if ((file = readdir(dir)))
	{
		if (file->d_type == 4)
		{
			ft_putstr_fd(path_name, 2);
			ft_putendl_fd(" is a directory", 2);
			free(dir);
			return (1);
		}
	}
	free(dir);
	return (0);
}
