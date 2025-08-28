/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:08:21 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/28 23:56:39 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <unistd.h>
#include "command.h"
#include "memory_allocator.h"
#include "string_utils.h"
#include "libft.h"
#include "env.h"
#include <sys/stat.h>

int	is_directory(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == -1)
		return (0);
	return (S_ISDIR(path_stat.st_mode));
}

int	file_status(char *file_name)
{
	if (access(file_name, F_OK) != 0)
		return (EX_NOTFOUND);
	if (access(file_name, X_OK) != 0)
		return (EX_NOEXEC);
	return (EXECUTION_SUCCESS);
}

int	is_absolute_command(char *command)
{
	return (ft_strchr(command, '/') != NULL);
}

char	*search_absolute_command(char *command)
{
	int	status;

	if (is_directory(command))
	{
		ft_putstr_fd("hash: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		safe_abort(EX_NOEXEC);
	}
	status = file_status(command);
	if (status != EXECUTION_SUCCESS)
		abort_command(command, status);
	return (command);
}

char	*search_command_path(char *command)
{
	char	**paths;
	char	*path_name;
	char	*full_path;
	int		status;
	int		index;

	if (is_absolute_command(command))
		return (search_absolute_command(command));
	path_name = get_env_value("PATH");
	if (path_name == NULL)
		return (NULL);
	paths = ft_split(path_name, ':');
	index = 0;
	while (paths[index])
	{
		full_path = str_arr_join((char *[]){paths[index++], "/", command}, 3);
		if (is_directory(full_path))
			continue;
		status = file_status(full_path);
		if (status == EXECUTION_SUCCESS)
			return (full_path);
		if (status == EX_NOEXEC)
			abort_command(full_path, status);
		safe_free_ptr(full_path, TEMPORARY);
	}
	return (NULL);
}
