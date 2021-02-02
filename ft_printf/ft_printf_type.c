/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:56:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/02 16:35:43 by dlanotte         ###   ########.fr       */
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

int		ft_sp(char *str, char *original_string, int i)
{
	int		printed;
	char	flag;

	while (original_string[i++] != 's')
		flag = ft_is_flag(original_string[i]);
	printed = ft_putstr(str);
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
