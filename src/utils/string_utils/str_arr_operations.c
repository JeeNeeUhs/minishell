/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:59:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/22 16:07:06 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memory_allocator.h"
#include <limits.h>
#include <stdlib.h>

char	*str_arr_join(char	**strings, int count)
{
	char	*new_str;
	int		i;
	int		len;
	int		offset;

	i = 0;
	len = 0;
	while (i < count)
	{
		if (strings[i])
			len += ft_strlen(strings[i]);
		i++;
	}
	if (len == 0)
		return (ft_strdup(""));
	new_str = (char *)safe_talloc(len + 1);
	i = 0;
	offset = 0;
	while (i < count)
	{
		if (strings[i])
			offset += ft_strlcpy(new_str + offset, strings[i], UINT_MAX);
		i++;
	}
	return (new_str);
}

void	str_arr_free(char	**strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
		safe_free_ptr(strings[i++], TEMPORARY);
}
