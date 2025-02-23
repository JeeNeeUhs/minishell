/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:46:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/23 13:03:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

int check_input_syntax(char* input);

// if operator token is first or last token, it will be syntax error
// if operator token is followed by another operator token, it will be syntax error
int check_tokens_syntax(t_token *token);

