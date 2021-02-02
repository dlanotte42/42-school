/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:56:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/02 19:56:43 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ip(int numb)
{
	char	*number;
	int		printed;

	number = ft_itoa(numb);
	printed = ft_putstr(number);
	free(number);
	return (printed);
}

int		ft_sp(char *str, char *or_stri, int i)
{
	int		printed;
	char	flag;
	int		width;

	width = 0;
	printed = i;
	while (or_stri[i++] != 's')
		if (ft_isdigit(or_stri[i]) && or_stri[i] != '0')
		{
			width = ft_find_numb(or_stri, i);
			break ;
		}
	i = printed;
	printed = 0;
	while (or_stri[i++] != 's')
		if (ft_is_flag(or_stri[i]) || width != 0)
		{
			printed = ft_exec_flag(ft_is_flag(or_stri[i]), ft_strlen(str), width);
			width = 0;
		}
	printed = printed + ft_putstr(str);
	return (printed);
}

int		ft_cp(char letter)
{
	int		printed;

	printed = ft_putchar(letter);
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
