/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 00:21:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/25 22:23:52 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	char *lol;
	char *str;

	lol = NULL;
	lol = malloc(sizeof(char) * 7);
	lol[0] = '0';
	lol[1] = '1';
	lol[2] = '2';
	lol[3] = '3';
	lol[4] = '2';
	lol[5] = '5';
	lol[6] = '\0';
	ft_putendl(ft_str_endcpy_until(lol, '2'));
	free(lol);
	return(1);
}
