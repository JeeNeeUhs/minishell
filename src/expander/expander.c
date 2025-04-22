/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:52 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/22 15:45:02 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "minishell.h"
#include "memory_allocator.h"
#include "env.h"
#include <stdlib.h>

void	expander(t_token *token)
{
	int	heredoc_flag;

	heredoc_flag = 0;
	while(token)
	{
		if (token->type & R_HERE)
			heredoc_flag = 1;
		else if (heredoc_flag && token->type & META_MASK)
			heredoc_flag = 0;
		else if (!heredoc_flag && token->type & W_DOUBLE_Q)
			expand_string(&token->content);
		// else if (!heredoc_flag && token->type & W_DOUBLE_Q)
		// 	field_split(token->content, token->type);
		token = token->next;
	}
}

/*
	Trace expanding in Bash {
		=> trace -e execve <your-input>
	},
*/
