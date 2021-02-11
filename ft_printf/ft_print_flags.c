/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:51:55 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/11 19:11:59 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_s_precision(t_param params, char *str, int printed)
{
	if (params.type == 'd' && params.is_neg)
		printed += ft_putchar('-');
	if (params.precision)
	{
		if (!params.precisions)
			params.d_zero = true;
		if (params.precisions >= ft_strlen(str))
			params.precisions -= ft_strlen(str);
		while (params.precisions--)
			printed += ft_putchar('0');
		if (!params.d_zero)
			printed += ft_putstr(str);
	}
	else
		printed += ft_putstr(str);
	return (printed);
}

int				ft_precision(t_param params, char *str)
{
	int			i;
	int			printed;

	i = 0;
	printed = 0;
	if (params.r_type == 'p' && !params.zero)
	{
		ft_putstr("0x");
		printed += 1;
	}
	if (params.type == 's')
	{
		if (params.precision)
			while (params.precisions-- && str[i])
				printed += ft_putchar(str[i++]);
		else
			printed += ft_putstr(str);
	}
	else if (params.type == 'd')
		printed += ft_s_precision(params, str, printed);
	else if (params.type == 'c' && str[0] == '\0')
		printed += ft_putchar(0);
	else if (params.type == 'c')
		printed += ft_putstr(str);
	return (printed);
}

static int		ft_s_width(t_param params, int printed, char *str)
{
	while (params.width > 0)
	{
		if (params.zero && params.type != 'd')
			printed += ft_putchar('0');
		else if (params.zero && params.type == 'd' && !params.precision)
			printed += ft_putchar('0');
		else
			printed += ft_putchar(' ');
		params.width--;
	}
	if (!params.minus)
		printed += ft_precision(params, str);
	return (printed);
}

int				ft_width(t_param params, char *str)
{
	int			printed;

	printed = 0;
	if (params.type == 'd' && params.is_neg)
		params.width -= 1;
	if (params.type == 'd' && params.is_neg && params.zero && !params.precision)
	{
		printed += ft_putchar('-');
		params.is_neg = false;
	}
	if (params.minus)
		printed += ft_precision(params, str);
	if (params.r_type == 'p')
	{
		params.width -= 2;
		if (params.zero)
			printed += ft_putstr("0x");
	}
	printed = ft_s_width(params, printed, str);
	return (printed);
}

int				ft_find_numb(char *str, int i)
{
	int							len;
	int							number;
	char						*number_char;

	len = 0;
	while (ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	if (!(number_char = malloc(sizeof(char) * (len + 1))))
		return ((int)NULL);
	i -= len;
	len = 0;
	while (ft_isdigit(str[i]))
	{
		number_char[len] = str[i];
		i++;
		len++;
	}
	number_char[len] = '\0';
	number = ft_atoi(number_char);
	free(number_char);
	return (number);
}