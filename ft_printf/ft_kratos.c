/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kratos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:16:00 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/11 19:16:31 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_calc_width(char *str, int i, t_param params)
{
	while (str[i++] != params.type)
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