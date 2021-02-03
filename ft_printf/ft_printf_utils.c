/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:19:13 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/03 19:15:33 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *ori, char *str, t_parameter parameters, int i)
{
	int printed;
	int	precision;
	int	add_zeros;

	add_zeros = 0;
	precision = 0;
	printed = 0;
	if (parameters.point)
		while (ori[i--])
			if (ori[i] == '.')
				break ;
	if ((precision = ft_find_numb(ori, i + 1)))
	{
		add_zeros = (ft_strlen(str) - precision);
		if (parameters.zero)
			while (add_zeros--)
				printed += ft_putchar('0');
		else
			while (add_zeros--)
				printed += ft_putchar(' ');
		while (*str && precision--)
		{
			printed = printed + ft_putchar(*str);
			str++;
		}
	}
	else
	{
		while (*str != '\0')
		{
			printed = printed + ft_putchar(*str);
			str++;
		}
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

int		ft_e(char flag, int len, t_parameter parameters)
{
	int		printed;

	printed = 0;
	parameters.width -= len;
	if (parameters.zero)
	{
		while (parameters.width-- && parameters.width >= 0)
			printed = printed + ft_putchar('0');
	}
	else if (!parameters.zero)
	{
		while (parameters.width-- && parameters.width >= 0 && !parameters.zero)
			printed = printed + ft_putchar(' ');
	}
	return (printed);
}
