/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/12 16:20:54 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minishell.h"
#include "token.h"

void	delimiter_state(char *str, int *i, t_token **head_token)
{
	t_token	*last_token;

	*i += skip_whitespace(&str[*i]);
	if (!(*head_token) && !str[*i])
		return ;
	last_token = get_last_token(*head_token);
	if (is_word_token_type(last_token->type))
		append_token(head_token, create_token(NULL, DELIMITER));
}

void	word_state(char *str, int *i, t_token **head_token)
{
	char			*content;
	t_token_type	token_type;
	int				s_index;

	s_index = *i;
	token_type = get_word_token_type(str[*i]);
	if (is_quoted_word_token_type(token_type))
	{
		*i = find_char_index(str, *i + 1, str[*i]);
		content = ft_substr(str, s_index + 1, (*i)++ - s_index - 1);
	}
	else
	{
		while (is_word_char(str[*i]))
			(*i)++;
		content = ft_substr(str, s_index, *i - s_index);
	}
	append_token(head_token, create_token(content, token_type));
}

void	operator_state(char *str, int *i, t_token **head_token)
{
	t_token_type	token_type;

	token_type = get_operator_token_type(&str[*i]);
	*i += (token_type == REDIRECTION_APPEND || token_type == HEREDOC) + 1;
	append_token(head_token, create_token(NULL, token_type));
}

t_state	get_tokenizer_state(char c)
{
	if (is_blank(c))
		return (delimiter_state);
	if (is_operator(c))
		return (operator_state);
	return (word_state);
}

t_token	*tokenizer(char *str)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = skip_whitespace(str);
	while (str[i])
		get_tokenizer_state(str[i])(str, &i, &tokens);
	return (tokens);
}
