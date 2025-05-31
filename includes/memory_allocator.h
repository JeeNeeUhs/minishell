/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:25:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/31 12:09:42 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_ALLOCATOR_H
# define MEMORY_ALLOCATOR_H

# include <stddef.h>

# define STD_EXIT 1

typedef struct s_memory_block
{
	void					*data;
	struct s_memory_block	*next;
}							t_memory_block;

typedef enum e_mem_type
{
	TEMPORARY = 0,
	PERSISTENT = 1
}							t_mem_type;

t_memory_block				**get_memory_head(t_mem_type mem_type);

void						*safe_talloc(size_t size);
void						*safe_palloc(size_t size);

void						safe_register_malloc(void *alloc_mem,
								t_mem_type mem_type);

void						safe_free(t_mem_type mem_type);
void						safe_free_ptr(void *ptr, t_mem_type mem_type);
void						safe_abort(int exit_code);

#endif
