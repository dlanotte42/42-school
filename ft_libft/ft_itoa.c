/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:16:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/16 20:01:11 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_numlen(int num)
{
	int		size;

	size = 0;
	while (num > 9)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_fill_table(char *numb_converted, int size, int num)
{
	numb_converted[size] = '\0';
	while (size)
	{
		numb_converted[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	return (numb_converted);
}

char	*ft_min_value(int size)
{
	char	*src;
	char	*str;
	int		i;

	i = 0;
	if (!(src = malloc(sizeof(char) * size)))
		return(NULL);
	str = "-2147483648";
	while (*str)
	{
		src[i] = *str;
		str++;
		i++;
	}
	return (str);
}

char    *ft_itoa(int num)
{
	int			size;
	int			is_negative;
	char		*numb_converted;

	is_negative = 0;
	if (num == -2147483648)
		return (ft_min_value(12));
	if (num < 0)
	{
		is_negative = 1;
		num = num * - 1;
	}
	size = ft_numlen(num);
	if (is_negative)
		size++;
	if (!(numb_converted = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_fill_table(numb_converted, size, num);
	if (is_negative)
		numb_converted[0] = '-';
	return (numb_converted);
}
