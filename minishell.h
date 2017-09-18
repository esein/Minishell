/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:20:11 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/18 12:05:24 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
char	**parse_entry(char *entry);

int		run_bin(char **args, char **env);

char	*read_entry();

int		execute(char **env);

char	*get_value(char **env, char *var);

int		print_prompt(char **env);

void	exit_error(char *error);

char	**create_env();
#endif
