/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/26 22:19:17 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include <stdlib.h>

t_memory_block	*get_memory_head(t_mem_type mem_type)
{
	static t_memory_block	temp_mem_blocks = {0};
	static t_memory_block	pers_mem_blocks = {0};
	
	if (mem_type == PERSISTENT)
		return (&pers_mem_blocks);
	return (&temp_mem_blocks);
}

t_memory_block	*get_last_memory_block(t_mem_type mem_type)
{
	t_memory_block	*mem_block;

	mem_block = get_memory_head(mem_type);
	while (mem_block->next)
		mem_block = mem_block->next;
	return (mem_block);
}

void	*safe_malloc(size_t size, t_mem_type mem_type)
{
	t_memory_block	*mem_block;
	void			*alloc_mem;

	alloc_mem = malloc(size);
	if (!alloc_mem)
		safe_abort(STD_EXIT);
	mem_block = malloc(sizeof(t_memory_block));
	if (!mem_block)
	{
		free(alloc_mem);
		safe_abort(STD_EXIT);
		return (NULL);
	}
	*mem_block = (t_memory_block){.data = alloc_mem, .next = NULL};
	get_last_memory_block(mem_type)->next = mem_block;
	return (alloc_mem);
}

void	*safe_talloc(size_t size)
{
	return (safe_malloc(size, TEMPORARY));
}

void	*safe_palloc(size_t size)
{
	return (safe_malloc(size, PERSISTENT));
}
