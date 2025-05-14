/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:52 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 15:16:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	expander(t_token **head_token)
{
	t_token	*next_token;
	t_token	*cur_token;
	int		heredoc_flag;

	cur_token = *head_token;
	heredoc_flag = 0;
	while (cur_token)
	{
		next_token = cur_token->next;
		if (cur_token->type & R_HERE)
			heredoc_flag = 1;
		else if (heredoc_flag && cur_token->type & META_MASK)
			heredoc_flag = 0;
		else if (!heredoc_flag && cur_token->type & W_DOUBLE_Q)
			expand_string(&cur_token->content);
		else if (!heredoc_flag && cur_token->type & W_UNQUOTED)
			word_split(cur_token);
		cur_token = next_token;
	}
	remove_token_by_flags(head_token, W_INVALID);
}
