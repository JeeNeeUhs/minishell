/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:44:28 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 06:44:28 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	len = get_len(n);
	nbr = n;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * -1;
	}
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	while (len >= 1)
	{
		str[(len--) - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
