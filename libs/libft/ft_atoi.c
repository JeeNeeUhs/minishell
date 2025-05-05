/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:37:08 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 14:37:08 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	skip_whitespace(const char *c)
{
	int	i;

	i = 0;
	while ((c[i] == ' ' || (c[i] >= 9 && c[i] <= 13)))
		i++;
	return (i);
}

static int	determine_sign(const char *c, int *i)
{
	int	sign;

	sign = 1;
	if ((c[*i] == '-' || c[*i] == '+'))
	{
		if (c[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	total;
	int	sign;
	int	i;

	total = 0;
	i = skip_whitespace(str);
	sign = determine_sign(str, &i);
	while ((str[i]) && (str[i] <= '9' && str[i] >= '0'))
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (sign * total);
}
