/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:02:24 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 16:09:34 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"
#include <stddef.h>

t_token	*lexer(char *input)
{
	if (!validate_quote(input))
		return (report_syntax_error(SYNTAX_ERR));
	return (tokenizer(input));
}
