/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:56:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/24 16:41:31 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iprintf(int numb)
{
	char	*number;
	int		printed;

	number = ft_itoa(numb);
	printed = ft_putstr(number);
	return (printed);
}

int		ft_sprintf(char *str)
{
	int		size;
	int		printed;

	size = ft_strlen(str);
	printed = ft_putstr(str);
	return (printed);
}

int		ft_cprintf(char letter)
{
	int 	printed;

	printed = ft_putchar(letter);
	return (printed);
}

int		ft_uprintf(unsigned int numb)
{
	char	*number;
	int		printed;

	number = ft_unsigned_itoa(numb);
	printed = ft_putstr(number);
	return (printed);
}
