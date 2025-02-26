/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aborter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:14 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/26 22:16:32 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include <stdlib.h>

void	safe_free(t_mem_type mem_type)
{
	t_memory_block	*mem_block;
	t_memory_block	*next_mem_block;

	mem_block = get_memory_head(mem_type)->next;
	while(mem_block)
	{
		next_mem_block = mem_block->next;
		free(mem_block->data);
		free(mem_block);
		mem_block = next_mem_block;
	}
	get_memory_head(mem_type)->next = NULL;
}

void	safe_free_ptr(void *ptr, int mem_block_type)
{
	t_memory_block	*mem_block;
	t_memory_block	*prev_mem_block;

	if (!ptr)
		return ;
	prev_mem_block = get_memory_head(mem_block_type);
	mem_block = prev_mem_block->next;
	while (mem_block)
	{
		if (mem_block->data == ptr)
		{
			prev_mem_block->next = mem_block->next;
			free(mem_block->data);
			free(mem_block);
			break ;
		}
		prev_mem_block = mem_block;
		mem_block = mem_block->next;
	}
}

void	safe_abort(int exit_code)
{	
	safe_free(PERSISTENT);
	safe_free(TEMPORARY);
	exit(exit_code);
}
 