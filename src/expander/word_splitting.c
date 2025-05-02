/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:43 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/02 16:56:27 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"
#include "memory_allocator.h"
#include "env.h"
#include "libft.h"

char	*get_ifs(void)
{
	char	*ifs;

	ifs = get_env_value("IFS");
	if (!ifs)
		ifs = ft_strdup(DEFAULT_IFS);
	return (ifs);
}

int create_delim_token(t_token **head_token, char *input, int index, char *delims)
{
	t_token	token;
	int		len;

	len = 0;
	while (input[index + len] && includes(delims, input[index + len]))
		len++;
	token = (t_token){
		.content = NULL,
		.type = DELIM,
		.next = NULL
	};
	prepend_token(head_token, create_token(token));
	return (len);
}

int	create_field_token(t_token **head_token, char *input, int index, char *delims)
{
	t_token	token;
	int		len;

	len = 0;
	while (input[index + len] && !includes(delims, input[index + len]))
		len++;
	token = (t_token){
		.content = ft_substr(input, index, len), // echotest,
		.type = W_SINGLE_Q,
		.next = NULL
	};
	prepend_token(head_token, create_token(token));
	return (len);
}

t_token	*field_split(char *input, char *delims)
{
	t_token	*tokens;
	int		index;

	tokens = NULL;
	index = 0;
	while(input[index])
	{
		if (includes(delims, input[index]))
			index += create_delim_token(&tokens, input, index, delims);
		else
			index += create_field_token(&tokens, input, index, delims);
	}
	return (reverse_token_list(tokens));
}

void	word_split(t_token *token)
{
	char	*ifs;
	char	*env_val;

	if (!is_var_start(token->content))
		return ;
	ifs = get_ifs();
	token->type = W_INVALID;
	if (token->content[1] == '?')
		env_val = ft_itoa(*get_exit_status());
	else
		env_val = get_env_value(token->content + 1);
	if (env_val)
		insert_tokens(&token, field_split(env_val, ifs));
	str_arr_free((char *[]){ifs, env_val}, 2);
}

/*
2.6.5 Field Splitting {
	=> https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_06_05
	=> default IFS value: {
		<space>,
		<tab>,
		<newline>
	}
}
*/
