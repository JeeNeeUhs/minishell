/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:43:44 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 15:56:25 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"

int	validate_pipes(t_token *token)
{
	t_token_type	prev_type;

	prev_type = PIPE;
	while (token != NULL)
	{
		if (token->type & PIPE && prev_type & PIPE)
			return (FAILURE);
		prev_type = token->type;
		token = token->next;
	}
	if (prev_type & PIPE)
		return (FAILURE);
	return (SUCCESS);
}


int	validate_redirections(t_token *token)
{
	t_token_type	prev_type;

	prev_type = WORD_MASK;
	while (token != NULL)
	{
		if (prev_type & REDIR_MASK && token->type & ~WORD_MASK)
			return (FAILURE);
		prev_type = token->type;
		token = token->next;
	}
	return (SUCCESS);
}

int	validate_quote(char *string)
{
	int		index;

	index = 0;
	while (string[index])
	{
		if (is_quote(string[index]))
		{
			index = find_char_index(string, index + 1, string[index]);
			if (string[index] == '\0')
				return (FAILURE);
		}
		index++;
	}
	return (SUCCESS);
}

int	is_max_heredoc_exceeded(t_token *token)
{
	int	here_count;

	here_count = 0;
	while (token)
	{
		if (token->type & R_HERE)
			here_count++;
		if (here_count > HEREDOC_MAX)
			return (1);
		token = token->next;
	}
	return (0);
}

int	validate_tokens(t_token *tokens)
{
	return (validate_redirections(tokens) && validate_pipes(tokens));
}
