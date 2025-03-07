/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:56:45 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/07 22:13:19 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "minishell.h"

char	*get_internal_field_separator(void)
{
	char	*ifs;

	ifs = get_env("IFS");
	if (!ifs)
		ifs = ft_strdup(" \t\n"); // default IFS value
	return (ifs);
}

void internal_field_split_state(t_token **token);


void	expander(t_token **tokens)
{
	t_state	state;
	t_token	*cur_token;

	cur_token = *tokens;
	while(cur_token)
	{
	}
}

/*
	2.6.5 Field Splitting {
		=> https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_06_05
		=> default IFS value: {
			<space>,
			<tab>,
			<newline>
		},
	},
	2.6.7 Quote Removal {
		=> The quote characters ( <backslash>, single-quote, and double-quote) that were present in the original word shall be removed unless they have themselves been quoted.
	},
	Trace expanding in Bash {
		=> trace -e execve <your-input>
	}
*/
