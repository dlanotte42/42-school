/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:19:13 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/02 20:12:14 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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

int		ft_exec_flag(char flag, int len, int width)
{
	int		printed;

	printed = 0;
	width -= len;
	while (width-- && width >= 0)
		printed = printed + ft_putchar(' ');

	return (printed);
}
