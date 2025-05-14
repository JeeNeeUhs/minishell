/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 14:59:20 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include "string_utils.h"
#include "minishell.h"
#include "token.h"

void	delimiter_state(char *input, int *i, t_token **head_token)
{
	t_token	*last;

	*i += skip_whitespace(&input[*i]);
	last = *head_token;
	if (input[*i] && (last->type & WORD_MASK))
		prepend_token(head_token, create_token((t_token){.type = DELIM}));
}

void	word_state(char *input, int *i, t_token **head_token)
{
	t_token			token;
	int				s_index;

	token.type = get_word_type(input[*i]);
	s_index = *i + (bool)(token.type & W_QUOTE_MASK);
	if (token.type & W_QUOTE_MASK)
		*i = find_char_index(input, *i + 1, input[*i]);
	else
	{
		if (is_var_start(&input[*i]))
		{
			(*i)++;
			if (input[*i] == '?')
				(*i)++;
			else
				while (is_var_char(input[*i]))
					(*i)++;
		}
		else
			while (is_word_char(input[*i]) && !is_var_start(&input[*i]))
				(*i)++;
	}
	token.content = ft_substr(input, s_index, *i - s_index);
	*i += (bool)(token.type & W_QUOTE_MASK);
	prepend_token(head_token, create_token(token));
}

void	operator_state(char *input, int *i, t_token **head_token)
{
	t_token	token;

	token = (t_token){
		.content = NULL,
		.type = get_operator_type(&input[*i])
	};
	*i += (bool)(token.type & (R_HERE | R_APPEND)) + 1;
	prepend_token(head_token, create_token(token));
}

t_state	get_tokenizer_state(char c)
{
	if (is_blank(c))
		return (delimiter_state);
	if (is_operator(c))
		return (operator_state);
	return (word_state);
}

t_token	*tokenizer(char *input)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = skip_whitespace(input);
	while (input[i])
		get_tokenizer_state(input[i])(input, &i, &tokens);
	return (reverse_token_list(tokens));
}
