/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:15:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 22:56:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "env.h"
#include "memory_allocator.h"
#include "string_utils.h"
#include <unistd.h>
#include "stdio.h"
#include <stdlib.h>

char	*get_current_directory(void)
{
	char	*current_dir;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (NULL);
	current_dir = ft_strdup(ft_strrchr(cwd, '/'));
	free(cwd);
	return (current_dir);
}

char	*get_prompt_var(char c)
{
	if (c == 's')
		return (SHELL_NAME);
	else if (c == 'h')
		return (get_env_value("HOSTNAME"));
	else if (c == 'u')
		return (get_env_value("USER"));
	else if (c == 'a')
		return ("\007");
	else if (c == 'e')
		return ("\033");
	return (NULL);
}

int	expand_prompt_var(char **input, int index)
{
	return (replace_with_expansion(
			input,
			index,
			get_prompt_var((*input)[index + 1]),
		2));
}

int	expand_current_dir(char **input, int index)
{
	char	*current_dir;
	int		result;

	current_dir = get_current_directory();
	result = replace_with_expansion(
			input,
			index,
			current_dir,
			2);
	safe_free_ptr(current_dir, TEMPORARY);
	return (result);
}

/* Return a string which will be printed as a prompt.  The string
	may contain special characters which are decoded as follows:
	https://tldp.org/HOWTO/Bash-Prompt-HOWTO/x329.html

	\s	the name of the shell
	\h	the host name
	\u  the user name
	\w	the current working directory
	\a	bell (ascii 07)
	\e
*/
char	*expand_prompt_string(char *input)
{
	char	*string;
	int		index;

	if (input == NULL)
		return (NULL);
	string = ft_strdup(input);
	index = 0;
	while (string[index])
	{
		if (string[index] == '\\' && includes(ESC_CHR, string[index + 1]))
		{
			if (string[index + 1] == 'w')
				index = expand_current_dir(&string, index);
			else
				index = expand_prompt_var(&string, index);
		}
		else
			index ++;
	}
	return (string);
}
