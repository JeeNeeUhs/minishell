/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:15:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/10 14:15:14 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "config.h"
#include "env.h"

int	is_special_char(char c)
{
	return (c == 's' || c == 'h'  || c == 'u' || c == 'w' || c == 'W');
}
char	*get_prompt_var(char c)
{
	if(c == 's')
		return (SHELL_NAME);
	else if (c == 'h')
		return (get_env_value("HOSTNAME"));
	else if (c == 'u')
		return (get_env_value("USER"));
	else if (c == 'w')
		return (get_env_value("PWD"));
	else if (c == 'W')
		return (strchr(get_env_value("PWD"), '/') + 1);
	else
		return (NULL);
}


int	expand_special_charachter(char **input, int index)
{
	char	*prompt_var;

	prompt_var = get_prompt_var(input[index + 1]);
	return (replace_with_expansion(
		input,
		index,
		prompt_var,
		2
	));
}

/* Return a string which will be printed as a prompt.  The string
	may contain special characters which are decoded as follows:

	\s	the name of the shell
	\h	the host name
	\u  the user name
	\w	the current working directory
	\W	the last element of $PWD
*/
char	*decode_prompt_string(char *string)
{
	char	*decoded_string;
	int		index;

	if (string == NULL)
		return (NULL);
	index = 0;
	while (string[index])
	{
		if (string[index] == '\\' && is_special_char(string[index + 1]))
			index += expand_special_charachter(&string, index);
		else
			index += 1;
	}
	return (string);
}
