/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:39:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/20 17:36:53 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "command.h"

void			echo_builtin(t_command *command);
void			cd_builtin(t_command *command);
void			pwd_builtin(t_command *command);
void			export_builtin(t_command *command);
void			unset_builtin(t_command *command);
void			env_builtin(t_command *command);
void			exit_builtin(t_command *command);

typedef void	(*t_builtin)(t_command *command);

t_builtin		get_builtin(char *command);

int				is_builtin(char *command);

void			report_export_error(char *variable);
#endif

