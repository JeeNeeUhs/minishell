/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsafe_str_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:33:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/26 08:35:06 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_unsafe_strdup(const char *s)
{
	char	*dup_str;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup_str = (char *)malloc(s_len + 1);
	if (!dup_str)
		return (0);
	ft_strlcpy(dup_str, s, s_len + 1);
	return (dup_str);
}

char	*ft_unsafe_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_unsafe_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
