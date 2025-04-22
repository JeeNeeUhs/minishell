/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:25:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/22 12:08:52 by hsamir           ###   ########.fr       */
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
	TEMPORARY,
	PERSISTENT
}							t_mem_type;

t_memory_block				*get_memory_head(t_mem_type mem_type);

void						*safe_talloc(size_t size);
void						*safe_palloc(size_t size);

void						safe_free(t_mem_type mem_type);
void						safe_free_ptr(void *ptr, t_mem_type mem_type);
void						safe_abort(int exit_code);

#endif

/*
	Allactor'u daha optimize yapmak adına yapılabilecekler =>abort
		double allocation yerine s_memory_block + size allocationu yapılıp mem_block->data = mem_block + sizeof(s_memory_block) yapabiliriz.
		bu sayede bir freeleme işlemi yapmak istersek mem_block->data - sizeof(s_memory_block) üzerinden yapıya ulasabiliriz. Eğer yapıyı iki yönlü listeye çevirirsek de sol ve sag tarafı baglayıp O(1) silme ye ulaşabiliriz.abort
	Ekleme yapmak için ise listenin sonu yerine başına ekleme yaparak (queue gibi) orada da o(1) karmaşıklığa ulaşabiliriz
*/
