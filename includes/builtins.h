/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:39:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/29 12:44:02 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "command.h"

int				echo_builtin(t_command *command);
int				cd_builtin(t_command *command);
int				pwd_builtin(t_command *command);
int				export_builtin(t_command *command);
int				unset_builtin(t_command *command);
int				env_builtin(t_command *command);
int				exit_builtin(t_command *command);

typedef int		(*t_builtin)(t_command *command);

t_builtin		get_builtin(char *command);

int				is_builtin(char *command);

int				report_export_error(char *variable);
int				builtin_error(char *message);

#endif
