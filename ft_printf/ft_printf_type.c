/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:56:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/06 19:26:20 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ip(int numb, char *ori_string, int i)
{
	char	*str;
	int		printed;
	t_param	params;

	printed = 0;
	params = ft_set_pa(params, ori_string, i, 'd');
	str = ft_itoa(numb);
	if (params.precision)
		printed = printed + ft_print_precision(params, str);
	if (params.width)
		printed = ft_print_zeros(params, printed, str);
	if (!printed && !params.precision)
		printed = printed + ft_putstr(str);
	free(str);
	return (printed);
}

int		ft_sp(char *str, char *ori_string, int i)
{
	int		printed;
	t_param	params;

	printed = 0;
	params = ft_set_pa(params, ori_string, i, 's');
	if (params.precision)
		printed = printed + ft_print_precision(params, str);
	if (params.width)
		printed = ft_print_zeros(params, printed, str);
	if (!printed && !params.precision)
		printed = printed + ft_putstr(str);
	return (printed);
}

int		ft_cp(char letter, char *ori_string, int i)
{
	int		printed;
	char	*str;
	t_param	params;

	if (!(str = malloc(sizeof(char) * 2)))
		return ((int)NULL);
	str[0] = letter;
	str[1] = '\0';
	params = ft_set_pa(params, ori_string, i, 'c');
	params.precision = false;
	if (params.width)
		printed = ft_print_zeros(params, printed, str);
	if (!printed)
		printed += ft_putchar(letter);
	free(str);
	return (printed);
}

int		ft_up(unsigned int numb)
{
	char	*number;
	int		printed;

	number = ft_unsigned_itoa(numb);
	printed = ft_putstr(number);
	free(number);
	return (printed);
}
