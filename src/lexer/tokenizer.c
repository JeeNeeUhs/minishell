/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 10:38:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "../libft/libft.h"

typedef 	void	(*t_state) (char* str, int* i, t_token **head_token);

void	delimineter_state (char* str, int* i, t_token **head_token)
{
	t_token	*new_token;
	t_token	*last_token;

	while(is_blank(str[*i]))
		(*i)++;
	if (!(*head_token))
		return ;
	last_token = get_last_token(*head_token);
	if (last_token->type == UNQUOTED_WORLD || last_token->type == DOUBLE_QUOTED_WORD || last_token->type == SINGLE_QUOTED_WORD)
	{
		new_token = create_token(head_token, NULL, DELIMINETER);
		if (!new_token)
			safe_exit(1, "Allocation error");
	}
}
int find_char_index(char str, int start_index, char c);

void	word_state (char* str, int* i, t_token **head_token)
{
	t_token		*new_token;
	t_token_type token_type;
	char		*content;
	int len;

	if (str[*i] == '\"')
	{
		token_type = DOUBLE_QUOTED_WORD;
		len = find_char_index(str, *i + 1, '\"');
	}
	else if (str[*i] == '\'')
	{
		token_type = SINGLE_QUOTED_WORD;
		len = find_char_index(str, *i + 1, '\'');
	}
	else
	{
		token_type = UNQUOTED_WORLD;
		len = 0;
		while (!is_blank(str[*i + len]) || !is_metacharacter(str[*i + len]) || !is_quote(str[*i + len]))
			len++;
	}
	content = ft_substr(str, *i, len);
	if (!content)
		safe_exit(1, "Allocation error");
	new_token = create_token(head_token, content, token_type);
	if (!new_token)
		safe_exit(1, "Allocation error");
	(*i) += len;
}

void	operator_state (char* str, int* i, t_token **head_token)
{
	t_token		*new_token;
	t_token_type token_type;


	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
			token_type = REDIRECTION_APPEND;
		else
			token_type = REDIRECTION_OUT;
	}
	else if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
			token_type = HEREDOC;
		else
			token_type = REDIRECTION_IN;
	}
	else
		token_type = PIPE;
	new_token = create_token(head_token, NULL, token_type);
	if (!new_token)
		safe_exit(1, "Allocation error");
	(*i) += 1 + (token_type == REDIRECTION_APPEND || token_type == HEREDOC);
}

t_state get_tokenizer_state(char c)
{
	if (is_blank(c))
		return (delimineter_state);
	else if (is_quote(c) || !is_metacharacter(c))
		return (word_state);
	else if (is_operator(c))
		return (operator_state);
	else
		return (NULL);
}
t_token	*tokenizer(char *str)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = skip_whitespace(str);
	while (str[i])
	{
		get_tokenizer_state(str[i])(str, &i, &tokens);
		i++;
	}
	return (tokens);
}
