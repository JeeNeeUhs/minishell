/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:40:55 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 18:40:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "../../includes/memory_allocator.h"

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup_str = (char *)safe_talloc(s_len + 1);
	if (!dup_str)
		return (0);
	ft_strlcpy(dup_str, s, s_len + 1);
	return (dup_str);
}
