/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:18:58 by akalayci          #+#    #+#             */
/*   Updated: 2022/01/08 13:55:12 by akalayci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_islong(const char *str, int i, int x)
{
	long	number;
	long	temp;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = number;
		number *= 10;
		number += str[i] - '0';
		if (temp > number)
		{
			if (x == -1)
				return (0);
			if (x == 1)
				return (-1);
		}
		i++;
	}
	return (number * x);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	return (ft_check_islong(str, i, x));
}
