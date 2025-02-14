/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:25:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/14 07:49:58 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include <stddef.h>

typedef struct s_memory_block
{
	void							*data;
	struct 			s_memory_block	*next;
}									t_memory_block;

t_memory_block						*get_memory_head();

void								*ft_malloc(size_t size);
void								ft_abort();
void								ft_abort_ptr(void *ptr);

#endif
