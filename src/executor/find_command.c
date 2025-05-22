/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:08:21 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/22 20:02:04 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <unistd.h>
#include "command.h"
#include "memory_allocator.h"
#include "string_utils.h"
#include "libft.h"
#include "env.h"

/* Return some flags based on information about this file.
   Zero is returned if the file is executable. */
int	file_status(char *file_name)
{
	if (access(file_name, F_OK) != 0)
		return (EX_NOTFOUND);
	if (access(file_name, X_OK) != 0)
		return (EX_NOEXEC);
	return (EXECUTION_SUCCESS);
}

/* Return 1 if STRING is an absolute program name; it is absolute if it
   contains any slashes.  This is used to decide whether or not to look
   up through $PATH. */
int	is_absolute_command(char *command)
{
	return (ft_strchr(command, '/') != NULL);
}

char*	search_absolute_command(char *command)
{
	int status;

	status = file_status(command);
	 /* If the file doesn't exist, quit now. */
	if (status != EXECUTION_SUCCESS)
		abort_command(command, status);
	return (command);
}

/* - COMMENT FROM KERNEL - https://github.com/torvalds/linux/blob/master/fs/namei.c
	* "." and ".." are special - ".." especially so because it has
	* to be able to know about the current root directory and
	* parent relationships. */
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
		full_path = str_arr_join((char *[]) {paths[index], "/", command}, 3);
		status = file_status(full_path);
		if (status == EXECUTION_SUCCESS)
			return (full_path);
		if (status == EX_NOEXEC)
			abort_command(full_path, status);
		safe_free_ptr(full_path, TEMPORARY);
		index++;
	}
	return (NULL);
}
