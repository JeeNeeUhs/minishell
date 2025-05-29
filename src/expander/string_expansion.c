/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:24:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/28 19:17:00 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "minishell.h"
#include "string_utils.h"
#include "memory_allocator.h"
#include "env.h"

char	*extract_env_var(char *input, int index)
{
	int	s_index;

	if (!is_var_start(input + index))
		return (NULL);
	s_index = ++index;
	while (input[index] && is_var_char(input[index]))
		index++;
	return (ft_substr(input, s_index, index - s_index));
}

int	replace_with_expansion(char **input, int index, char *rep, int offset)
{
	char	*prefix;
	char	*suffix;

	prefix = *input;
	prefix[index] = '\0';
	suffix = prefix + index + offset; //echo "lazy_loading$test%lazy_loading%"
	*input = str_arr_join((char *[]){
			prefix,
			rep,
			suffix}, 3);
	if (rep != NULL)
		index += ft_strlen(rep);
	str_arr_free((char *[]){prefix}, 1);
	return (index);
}

int	expand_variable(char **input, int index) //test$test
{
	char	*env_name;
	int		result;

	env_name = extract_env_var(*input, index);
	result = replace_with_expansion(
			input,
			index,
			get_env_value(env_name),
			ft_strlen(env_name) + 1);
	safe_free_ptr(env_name, TEMPORARY);
	return (result);
}

int	expand_exit_status(char **input, int index) //test$?test
{
	int		result;
	char	*exit;

	exit = ft_itoa(*exit_status());
	result = replace_with_expansion(
			input,
			index,
			exit,
			2);
	safe_free_ptr(exit, TEMPORARY);
	return (result);
}

void	expand_string(char **input)
{
	char	*str;
	int		index;

	str = *input;
	index = 0;
	while (str[index])
	{
		if (is_var_start(str + index))
		{
			if (str[index + 1] == '?')
				index = expand_exit_status(&str, index);
			else
				index = expand_variable(&str, index);
		}
		else
			index++;
	}
	*input = str;
}
