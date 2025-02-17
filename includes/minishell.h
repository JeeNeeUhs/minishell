/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/17 08:30:21 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

typedef enum e_token_type
{
	WORLD,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	COMMAND,
	OPERATOR //todo i have to seperate that
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	void			*next;
}	t_token;

#endif
