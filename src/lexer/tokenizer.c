/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/17 14:28:08 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "../libft/libft.h"

typedef 	void	(*t_state) (char* str, int* i, t_token **head_token);

t_state get_tokenizer_state(char c)
{

}
t_token	*tokenizer(char *str)asd
{
	t_token	*tokens;
	void	*(*t_state) (char* str, int* i, t_token **head_token) state;
	t_state	state;
	int		i;

	tokens = NULL;
	i = skip_whitespace(str);
	while (str[i])
	{
		t_state = determinate_state()
		if (is_blank(str[i]))
			blank_state()
		else if (is_quote(str[i]) || !is_metacharacter(str[i]))
			word_state(); // word_state
		else if ()
			//TODO
	}
	return (tokens);
}
