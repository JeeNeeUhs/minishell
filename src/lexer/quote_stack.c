/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:11:54 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/18 12:11:54 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "memory-allocator.h"

t_quote* get_current_quote(t_quote* quote)
{
	if (quote)
		return (NULL);
	while(quote->next != NULL)
		quote = quote->next;
	return (quote);
}

int	push_quote(t_quote** head_quote, t_token_type quote_type)
{
	t_quote	*new_quote;

	new_quote = ft_malloc(sizeof(t_quote));
	if (!new_quote)
		return (FAILURE);
	*new_quote = (t_quote){.quote_type = quote_type, .next = *head_quote};
	*head_quote = new_quote;
	return (SUCCESS);
}

void pop_quote(t_quote** head_quote)
{
	t_quote *next_quote;

	if (*head_quote == NULL)
		return ;
	next_quote = (*head_quote)->next;
	ft_free_ptr(*head_quote);
	*head_quote = next_quote;
}
