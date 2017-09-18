/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 00:21:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 01:11:42 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	char **lol;
	int i = 0;
	lol = ft_strsplit_whitespace(argv[1]);
	ft_print_char_tab(lol, '\n');
	while (lol[i] != 0)
	{
		free(lol[i]);
		i++;
	}
	free(lol);
	return (0);
}
