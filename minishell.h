/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:20:11 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/09 19:29:24 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
# include <dirent.h>
# include <sys/utsname.h>

int		check_builtin(char *name);

int		check_rights(char *path_name);

int		check_directory(char *path_name);

void	echo(char **args);

char	*check_path(char *name, char **env);

char	**parse_entry(char *entry);

char	*find_bin(char **env, char *name);

int		find_name(char *wd, char *name);

int		run_bin(char **args, char **env, char *cmd);

char	**set_env(char **env, char **args);

char	**unset_env(char **env, char **args);

char	**add_var_env(char **env, char *new_var, char *new_value);

char	**rm_var_env(char **env, char *var);

int		change_value(char **env, char *var, char *new_value);

int		check_var(char **env, char *var);

char	*read_entry();

int		run_loop(char **env);

char	*get_value(char **env, char *var);

int		print_prompt(char **env);

void	exit_error(char *error);

char	**create_env();
#endif
