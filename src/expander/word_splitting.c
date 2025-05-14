/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:43 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 15:20:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"
#include "string_utils.h"
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

int	create_delim_token(t_token **head, char *input, int index, char *sep)
{
	t_token	token;
	int		len;

	len = 0;
	while (input[index + len] && includes(sep, input[index + len]))
		len++;
	token = (t_token){
		.content = NULL,
		.type = DELIM,
		.next = NULL
	};
	prepend_token(head, create_token(token));
	return (len);
}

int	create_field_token(t_token **head, char *input, int index, char *sep)
{
	t_token	token;
	int		len;

	len = 0;
	while (input[index + len] && !includes(sep, input[index + len]))
		len++;
	token = (t_token){
		.content = ft_substr(input, index, len), // echotest,
		.type = W_SINGLE_Q,
		.next = NULL
	};
	prepend_token(head, create_token(token));
	return (len);
}

t_token	*field_split(char *input, char *delims)
{
	t_token	*tokens;
	int		index;

	tokens = NULL;
	index = 0;
	while (input[index])
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

	if (!is_var_start(token->content))
		return ;
	ifs = get_ifs();
	expand_string(&token->content);
	if (ft_strlen(token->content) != 0)
		insert_tokens(&token, field_split(token->content, ifs));
	token->type |= W_INVALID;
	str_arr_free((char *[]){ifs}, 1);
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
