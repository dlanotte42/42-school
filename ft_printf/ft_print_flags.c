/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:51:55 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/12 20:29:00 by dlanotte         ###   ########.fr       */
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

static int		ft_ss_precision(t_param params, char *str, int printed)
{
	if (params.type == 'd')
		printed += ft_s_precision(params, str, printed);
	else if (params.type == 'c' && str[0] == '\0')
		printed += ft_putchar(0);
	else if (params.type == 'c')
		printed += ft_putstr(str);
	return (printed);
}

int				ft_precision(t_param params, char *str)
{
	int			i;
	int			printed;

	i = 0;
	printed = 0;
	if ((params.r_type == 'p' && !params.zero) || (!params.zeros_exe
		&& params.r_type == 'p'))
	{
		ft_putstr("0x");
		printed += 1;
		params.zeros_exe = true;
	}
	if (params.type == 's')
	{
		if (params.precision)
			while (params.precisions-- && str[i])
				printed += ft_putchar(str[i++]);
		else
			printed += ft_putstr(str);
	}
	else
		printed = ft_ss_precision(params, str, printed);
	return (printed);
}

static int		ft_s_width(t_param params, int printed, char *str)
{
	if (params.r_type == 'p')
	{
		params.width -= 2;
		if (params.zero && params.width > params.precisions
			&& !params.zeros_exe)
		{
			printed += ft_putstr("0x");
			params.zeros_exe = true;
		}
	}
	while (params.width > 0)
	{
		if (params.zero && params.type != 'd')
			printed += ft_putchar('0');
		else if (params.zero && params.type == 'd' &&
				!params.precision && !params.minus)
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
	params.zeros_exe = false;
	if (params.type == 'd' && params.is_neg)
		params.width -= 1;
	if (params.type == 'd' && params.is_neg && params.zero && !params.precision)
	{
		printed += ft_putchar('-');
		params.is_neg = false;
	}
	if (params.minus)
		printed += ft_precision(params, str);
	printed = ft_s_width(params, printed, str);
	return (printed);
}
