/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_support.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:27:32 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/05 15:29:28 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_calc_width(char *str, int i, t_param params)
{
	while (str[i++] != params.type)
		if (ft_isdigit(str[i]) && str[i] != '0')
			if (str[i - 1] != '.')
				return (ft_find_numb(str, i));
	return (0);
}

int				ft_calc_precision(char *str, int i, t_param params)
{
	if (ft_isdigit(str[i + 1]))
		return (ft_find_numb(str, i + 1));
	return (0);
}

int				ft_print_precision(t_param params, char *str)
{
	int 	printed;
	
	printed = 0;
	while(params.precisions-- && str[printed] && params.type == 's')
		if (!params.width)
			ft_putchar(str[printed++]);
	return (printed);
}

int				ft_print_zeros(t_param params, int printed, char *str)
{
	int		to_print;
	int		i;

	i = 0;
	if (!params.precision)
		printed = ft_strlen(str);
	to_print = printed;
	params.width -= printed;
	while(--params.width >= 0)
		if (params.zero)
			printed += ft_putchar('0');
		else
			printed += ft_putchar(' ');
	while(to_print--)
		ft_putchar(str[i++]);
	return (printed);
}