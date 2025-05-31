/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/31 09:13:44 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/memory_allocator.h"
#include <stdlib.h>

t_memory_block	**get_memory_head(t_mem_type mem_type)
{
	static t_memory_block	*mem_blocks[2] = {0};

	return (&mem_blocks[mem_type]);
}

void	*safe_malloc(size_t size, t_mem_type mem_type)
{
	t_memory_block	**head;
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
	}
	head = get_memory_head(mem_type);
	*mem_block = (t_memory_block){
		.data = alloc_mem,
		.next = *head
	};
	*head = mem_block;
	return (alloc_mem);
}

void safe_register_malloc(void *alloc_mem, t_mem_type mem_type)
{
	t_memory_block	**head;
	t_memory_block	*mem_block;

	mem_block = malloc(sizeof(t_memory_block));
	if (!mem_block)
	{
		free(alloc_mem);
		safe_abort(STD_EXIT);
	}
	head = get_memory_head(mem_type);
	*mem_block = (t_memory_block){
		.data = alloc_mem,
		.next = *head
	};
	*head = mem_block;
}

void	*safe_talloc(size_t size)
{
	return (safe_malloc(size, TEMPORARY));
}

void	*safe_palloc(size_t size)
{
	return (safe_malloc(size, PERSISTENT));
}
