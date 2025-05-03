/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:26:12 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/03 13:11:29 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include "minishell.h"

#define WORD_STATE 1
#define DELIM_STATE 0

void	str_append(char **input, char *tail)
{
	char	*head;

	head = *input;
	*input = str_arr_join((char *[]){
		head,
		tail}, 2);
	free(head);
}


void	join_word_parts(t_token **head_token)
{
	t_token	*word;
	t_token	*token;
	int		join_flag;

	join_flag = 0;
	token = *head_token;
	while(token != NULL)
	{
		if (token->type & WORD_MASK && join_flag)
		{
			str_append(&word->content, token->content);
			word->type |= token->type;
			token->type = W_INVALID;
		}
		else if (token->type & WORD_MASK && !join_flag)
		{
			word = token;
			join_flag = 1;
		}
		else
			join_flag = 0;
		token = token->next;
	}
	remove_token_by_flags(head_token, W_INVALID);
}

