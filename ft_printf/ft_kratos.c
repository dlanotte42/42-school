/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kratos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:16:00 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/11 23:41:34 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_calc_width(char *str, int i, t_param params)
{
	while (str[i++] != params.type && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			if (str[i - 1] != '.')
				return (ft_find_numb(str, i));
	}
	return (0);
}

int				ft_calc_precision(char *str, int i, t_param params)
{
	if (ft_isdigit(str[i + 1]))
		return (ft_find_numb(str, i + 1));
	return (0);
}

t_param			ft_check_params(t_param params, char *str, char type)
{
	if (params.width < 0)
	{
		params.minus = true;
		params.width *= -1;
	}
	if (params.precision && params.precisions < 0)
	{
		params.precision = false;
		params.precisions = 0;
	}
	if (type == 's')
	{
		if (params.precision && params.precisions <= ft_strlen(str))
			params.width -= params.precisions;
		else
			params.width -= ft_strlen(str);
	}
	else if (type == 'd')
	{
		if (params.precision && params.precisions >= ft_strlen(str))
			params.width -= params.precisions;
		else if (params.precision && params.precisions == 0 
				&& str[0] == '0' && str[1] == '\0')
			params.width = params.width;
		else
			params.width -= ft_strlen(str);
	}
	return (params);
}