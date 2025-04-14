/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:52 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/13 21:14:39 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "minishell.h"
#include "memory_allocator.h"
#include "env.h"

char	*expand_string(char* str, int is_unquoted);

// void	word_split(t_token* prev_token, t_token **cur_token)
// {
// 	char		*expand_str;

// 	expand_str = expand_string((*cur_token)->content, 1);
// 	if (!is_null_or_empty(expand_str))
// 		insert_tokens(cur_token, field_split(expand_str));
// 	safe_free_ptr(expand_str, TEMPORARY);
// 	remove_token(prev_token, cur_token);
// }

void	expander(t_token **tokens)
{
	t_state	state;
	t_token	*cur_token;

	while(cur_token)
	{

	}
}

/*
	Trace expanding in Bash {
		=> trace -e execve <your-input>
	},
*/
