/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/13 22:31:44 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include <stdlib.h>

t_memory_block	*mem_blocks(void)
{
	static t_memory_block	mem_blocks = {0};

	return (&mem_blocks);
}

t_memory_block	*last_alloc_mem_block(void)
{
	t_memory_block	*mem_block;

	mem_block = mem_blocks();
	while (mem_block->next)
		mem_block = mem_block->next;
	return (mem_block);
}

void	*ft_malloc(size_t size)
{
	t_memory_block	*mem_block;
	void			*alloc_mem;

	alloc_mem = malloc(size);
	if (!alloc_mem)
		return (NULL);// todo abort all allocated memory
	mem_block = malloc(sizeof(t_memory_block));
	if (!mem_block)
		return (NULL);// todo abort all allocated memory
	*mem_block = (t_memory_block){.data = alloc_mem, .next = NULL};
	last_alloc_mem_block()->next = mem_block;
}
