/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:43:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/10 20:37:11 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_entry()
{
	char *entry;

	entry = NULL;
	get_next_line(0 , &entry);
	return (entry);
}

char	**parse_entry(char *entry)
{
	char	**args;

	args = ft_strsplit(entry, ' ');
	return (args);
}

int		main()
{
	char	*entry;
	char	**args;
	int		end;

	end = 1;
	while ( end > 0)
	{
		ft_putstr("$> ");
		entry = get_entry();
		args = parse_entry(entry);
		end = execute(args);
		free(entry);
		free(args);
	}
	return (0);
}
