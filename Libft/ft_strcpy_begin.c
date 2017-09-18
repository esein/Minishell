/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:55:27 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 10:55:49 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_begin(char *s, int i)
{
	char	*new;

	new = ft_strnew(ft_strlen(s) - i + 1);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
