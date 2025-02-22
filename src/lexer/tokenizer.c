/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 18:13:23 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "token.h"
#include "../libft/libft.h"

void	delimineter_state(char *str, int *i, t_token **head_token)
{
	t_token	*last_token;
	t_token	*new_token;

	*i += skip_whitespace(&str[*i]);
	if (!(*head_token))
		return ;
	last_token = get_last_token(*head_token);
	if (is_word_token(last_token->type))
	{
		new_token = create_token(NULL, DELIMINETER);
		if (!new_token)
			safe_exit(1, "Allocation error");
		append_token(head_token, new_token);
	}
}
void	word_state(char *str, int *i, t_token **head_token)
{
	t_token			*new_token;
	char			*content;
	t_token_type	token_type;
	int				s_index;

	s_index = *i;
	token_type = get_word_type(str[*i]);
	if (token_type == DOUBLE_QUOTED_WORD || token_type == SINGLE_QUOTED_WORD)
	{
		*i = find_char_index(str, *i + 1, str[*i]);
		content = ft_substr(str, s_index + 1,  (*i)++ - s_index - 1);
	}
	else
	{
		while (str[*i] && !is_metacharacter(str[*i]) && !is_quote(str[*i]))
			(*i)++;
		content = ft_substr(str, s_index, *i - s_index);
	}
	if (!content)
		safe_exit(1, "Allocation error");
	new_token = create_token(content, token_type);
	if (!new_token)
		safe_exit(1, "Allocation error");
	append_token(head_token, new_token);
}

void	operator_state(char *str, int *i, t_token **head_token)
{
	t_token			*new_token;
	t_token_type	token_type;

	token_type = get_operator_type(&str[*i]);
	new_token = create_token(NULL, token_type);
	if (!new_token)
		safe_exit(1, "Allocation error");
	append_token(head_token, new_token);
	(*i) += 1 + (token_type == REDIRECTION_APPEND || token_type == HEREDOC);
}

t_state	get_tokenizer_state(char c)
{
	if (is_blank(c))
		return (delimineter_state);
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
