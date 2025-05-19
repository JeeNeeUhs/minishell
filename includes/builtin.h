/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:39:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/19 15:08:59 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "command.h"

int		ft_echo(t_command *cmd);
int		ft_cd(t_command *cmd);
int		ft_pwd(t_command *cmd);
int		ft_export(t_command *cmd);
int		ft_unset(t_command *cmd);
int		ft_env(t_command *cmd);
int		ft_exit(t_command *cmd);


typedef int	(*t_builtin)(t_command *cmd);

int		is_builtin(char *cmd);
int		is_simple_command(t_command *cmd);

#endif

