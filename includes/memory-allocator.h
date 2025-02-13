/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:25:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/13 20:48:58 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

typedef struct s_memory_block
{
	void			*data;
	t_memory_block	*next;
}					t_memory_block;

#endif
