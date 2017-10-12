/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 00:21:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/12 04:12:17 by gcadiou          ###   ########.fr       */
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
//	ft_putendl(ft_str_endcpy_until(lol, '2'));
	char **s;
	s = ft_mal_double_tab(s, 2, 1);
	s[0]=ft_strdup("ls");
	s[1]=NULL;
	execve("/bin/ls", s, NULL);
	free(lol);
	return(1);
}
