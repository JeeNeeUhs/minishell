/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persistent_str_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:33:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/05 19:18:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memory_allocator.h"
#include <stdlib.h>

char	*ft_pstrdup(const char *s)
{
	char	*dup_str;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup_str = (char *)safe_palloc(s_len + 1);
	if (!dup_str)
		return (0);
	ft_strlcpy(dup_str, s, s_len + 1);
	return (dup_str);
}

char	*ft_psubstr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_pstrdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)safe_palloc(len + 1);
	if (!substr)
		return (0);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
