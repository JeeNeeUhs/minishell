/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:25:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/14 06:46:54 by hsamir           ###   ########.fr       */
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

void								*ft_malloc(size_t size);
void								ft_abort();
t_memory_block						*get_memory_head();

#endif
