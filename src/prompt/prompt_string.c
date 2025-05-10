/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:15:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/10 17:13:27 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "env.h"
#include "memory_allocator.h"
#include <unistd.h>
#include "stdio.h"

int	is_special_char(char c)
{
	return (c == 's' || c == 'h'  || c == 'u' || c == 'w');
}

/* As an extension to the POSIX.1-2001 standard, glibc's getcwd()
	allocates the buffer dynamically using malloc(3) if buf is NULL.
*/
char	*get_current_dir(void)
{
	char	*current_dir;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (NULL);
	current_dir = ft_strdup(ft_strrchr(cwd, '/'));
	safe_free_ptr(cwd, TEMPORARY);
	return (current_dir);
}

char	*get_prompt_var(char c)
{
	char	*prompt_var;

	if(c == 's')
		prompt_var = get_env_value("SHELL_NAME");
	else if (c == 'h')
		prompt_var = get_env_value("HOSTNAME");
	else if (c == 'u')
		prompt_var = get_env_value("USER");
	else if (c == 'w')
		prompt_var = get_current_dir();
	else
		prompt_var = NULL;
	return (prompt_var);
}

int	expand_prompt_var(char **input, int index)
{
	return (replace_with_expansion(
		input,
		index,
		get_prompt_var((*input)[index + 1]),
		2
	));
}

int	expand_path(char **input, int index)
{
	char	*current_dir;
	int		result;

	current_dir = get_current_dir();
	result = replace_with_expansion(
		input,
		index,
		current_dir,
		2
	);
	safe_free_ptr(current_dir, TEMPORARY);
	return (result);
}

/* Return a string which will be printed as a prompt.  The string
	may contain special characters which are decoded as follows:

	\s	the name of the shell
	\h	the host name
	\u  the user name
	\w	the current working directory
*/
char	*decode_prompt_string(char *input)
{
	char	*string;
	int		index;

	if (input == NULL)
		return (NULL);
		index = 0;
	string = ft_strdup(input);
	while (string[index])
	{
		if (string[index] == '\\' && is_special_char(string[index + 1]))
		{
			if (string[index + 1] == 'w')
				index = expand_path(&string, index);
			else
				index = expand_prompt_var(&string, index);
		}
		else
			index ++;
	}
	return (string);
}
