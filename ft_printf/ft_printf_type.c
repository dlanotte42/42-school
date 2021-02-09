/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:56:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/09 19:19:30 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ip(int numb, char *ori_string, int i, int *aster)
{
	char	*str;
	int		printed;
	t_param	params;

	printed = 0;
	params.is_negative = false;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i, 'd');
	if (numb < 0)
		params.is_negative = true;
	str = ft_itoa(numb);
	if (params.precision && params.precisions >= ft_strlen(str))
		params.width -= params.precisions;
	else if (params.precisions <= ft_strlen(str) && params.precision)
	{
		params.precisions = 0;
		params.precision = false;
		params.zero = false;
	}
	if (!params.precision)
		params.width -= ft_strlen(str);
	printed += ft_width(params, str);
	free(str);
	return (printed);
}

int		ft_sp(char *str, char *ori_string, int i, int *aster)
{
	int		printed;
	t_param	params;
	bool	alloc;

	alloc = false;
	printed = 0;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i, 's');
	if (!str)
	{
		alloc = true;
		str = return_null();
	}
	if (params.precision && params.precisions <= ft_strlen(str))
		params.width -= params.precisions;
	else
		params.width -= ft_strlen(str);
	printed += ft_width(params, str);
	if (alloc)
		free(str);
	return (printed);
}

int		ft_cp(char letter, char *ori_string, int i, int *aster)
{
	int		printed;
	char	*str;
	t_param	params;

	if (!(str = malloc(sizeof(char) * 2)))
		return ((int)NULL);
	str[0] = letter;
	str[1] = '\0';
	params = ft_set_pa(params, ori_string, i, 'c');
	params.width -= ft_strlen(str);
	printed += ft_width(params, str);
	printed += ft_putchar(letter);
	free(str);
	return (printed - 1);
}

int		ft_up(unsigned int numb, char *ori_string, int i, int *aster)
{
	char	*str;
	int		printed;
	t_param	params;

	params = ft_set_pa(params, ori_string, i, 'd');
	str = ft_unsigned_itoa(numb);
	if (params.precision && params.precisions >= ft_strlen(str))
		params.width -= params.precisions;
	else if (params.precisions <= ft_strlen(str) && params.precision)
	{
		params.precisions = 0;
		params.precision = false;
		params.zero = false;
	}
	if (!params.precision)
		params.width -= ft_strlen(str);
	printed += ft_width(params, str);
	free(str);
	return (printed - 1);
}
