/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 08:38:24 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 10:51:46 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut_until(char *s, char c)
{
	int		i;
	int		len;
	char	*new;

	i = ft_strlentil(s, c, 0);
	len = ft_strlen(&(s[i]));
	new = ft_memalloc(sizeof(char) * (len + 1));
	check_malloc(new, "ft_strcut_until");
	new = ft_strncpy(new, &(s[i]), len);
	free(s);
	return (new);
}
