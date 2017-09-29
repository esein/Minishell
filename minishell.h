/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:20:11 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/29 18:09:49 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
# include <dirent.h>
# include <sys/utsname.h>

int		check_builtin(char *name);
void		set_env(char **env, char **args);

void	set_env(char **env, char **args);
void	echo(char **args);

char	*check_path(char *name);
char	**parse_entry(char *entry);

char	*find_bin(char **env, char *name);

int		run_bin(char **args, char **env, char *cmd);

char	*read_entry();

int		run_loop(char **env);

char	*get_value(char **env, char *var);

int		print_prompt(char **env);

void	exit_error(char *error);

char	**create_env();
#endif
