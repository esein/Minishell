/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:43:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/16 05:24:24 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_entry()
{
	char *entry;
	int		ret;

	entry = NULL;
	ret = get_next_line(0 , &entry);
	ft_putnbr(ret);
	ft_putstr(entry);
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

	end = 0;
	entry = NULL;
	while (end == 0)
	{
		ft_putstr("$> ");
		entry = read_entry();
		args = parse_entry(entry);
		end = execute(args);
		if (entry != NULL)
			free(entry);
		if (args != NULL)
			free(args);
//		end = 1;
	}
	return (0);
}
