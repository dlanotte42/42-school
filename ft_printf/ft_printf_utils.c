/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:19:13 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/24 16:33:38 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	int printed;

	printed = 0;
	printed++;
	write(1, &c, 1);
	return (printed);
}

int		ft_putstr(char *str)
{
	int printed;

	printed = 0;
	while (*str != '\0')
	{
		printed = printed + ft_putchar(*str);
		str++;
	}
	return (printed);
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
		if (str[i] == '%' && ft_calc_paramenter(str, i))
			remove = remove + ft_calc_paramenter(str, i);
		else if (str[i] == '%' && str[i + 1] == '%')
			remove += 2;
		i++;
	}
	i = 0;


	return (remove);
}