/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:26:12 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/02 16:56:45 by hsamir           ###   ########.fr       */
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


void	join_word_parts(t_token *tokens)
{
	t_token	*word;
	int		join_flag;

	join_flag = 0;
	while(tokens != NULL)
	{
		if (tokens->type & W_INVALID)
		{
			tokens = tokens->next;
			continue;
		}
		else if (tokens->type & WORD_MASK && join_flag)
		{
			str_append(&word->content, tokens->content);
			word->type |= tokens->type;
			tokens->type = W_INVALID;
		}
		else if (tokens->type & WORD_MASK && !join_flag)
		{
			word = tokens;
			join_flag = 1;
		}
		else
			join_flag = 0;
		tokens = tokens->next;
	}
}

