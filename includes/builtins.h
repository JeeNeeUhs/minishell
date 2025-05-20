/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:39:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/20 17:33:06 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "command.h"

void			echo_builtin(t_command *cmd);
void			cd_builtin(t_command *cmd);
void			pwd_builtin(t_command *cmd);
void			export_builtin(t_command *cmd);
void			unset_builtin(t_command *cmd);
void			env_builtin(t_command *cmd);
void			exit_builtin(t_command *cmd);

typedef void	(*t_builtin)(t_command *cmd);

t_builtin		get_builtin(char *command);

int				is_builtin(char *command);

void			report_export_error(char *variable);
#endif

