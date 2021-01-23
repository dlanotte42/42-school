/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:35:28 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/23 17:40:14 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_numlen(unsigned int num)
{
	int			size;

	size = 0;
	while (num > 9)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

int		ft_strlen(char *str)
{

	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_calc_percent(char *str)
{
	int		i;
	int		remove;

	i = 0;
	remove = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_isalnum((int)str[i + 1]))
			remove += 2;
		i++;
	}
	return (remove);
}