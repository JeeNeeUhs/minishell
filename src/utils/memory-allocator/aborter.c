/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aborter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:14 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/14 06:47:10 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include <stdlib.h>

void	ft_abort()
{
	t_memory_block	*mem_block;
	t_memory_block	*next_mem_block;

	mem_block = get_memory_head()->next;
	while(mem_block)
	{
		next_mem_block = mem_block->next;
		free(mem_block->data);
		free(mem_block);
		mem_block = next_mem_block;
	}
	get_memory_head()->next = NULL;
}
