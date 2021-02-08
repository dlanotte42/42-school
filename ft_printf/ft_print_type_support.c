/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_support.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:27:32 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/08 23:12:49 by zxcvbinz         ###   ########.fr       */
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

int     ft_precision(t_param params, char *str)
{
    int     i;
    int     printed;
    
    i = 0;
    printed = 0;
    if (params.type == 's')
    {
        if (params.precision)
            while(params.precisions-- && str[i])
                printed += ft_putchar(str[i++]);
        else 
            printed += ft_putstr(str);
    }
    else if (params.type == 'd')
	{
        if (params.precision)
        {
			if (params.precisions >= ft_strlen(str))
				params.precisions -= ft_strlen(str);
            while(params.precisions--)
                printed += ft_putchar('0');
            printed += ft_putstr(str);
        }
        else
            printed += ft_putstr(str);
	}
    return (printed);
}

int     ft_width(t_param params, char *str)
{
    int         printed;
    
    printed = 0;
    if (params.minus)
        printed += ft_precision(params, str);
    while(params.width > 0)
    {
        if (params.zero)
            printed += ft_putchar('0');
        else
            printed += ft_putchar(' ');
        params.width--;
    }
    if (!params.minus)
        printed += ft_precision(params, str);
	return (printed);
}