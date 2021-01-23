/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:49:41 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/23 17:56:25 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iprintf(int numb)
{
	int size;
	char *number;
	
	number = ft_itoa(numb);
	ft_putstr(number);
	size = ft_strlen(number);
	return (size);
}

int		ft_sprintf(char *str)
{
	int size;

	size = ft_strlen(str);
	ft_putstr(str);
	return(size);
}

int		ft_cprintf(char letter)
{
	ft_putchar(letter);
	return (1);
}

int		ft_uprintf(unsigned int numb)
{
	int size;
	char *number;
	
	number = ft_unsigned_itoa(numb);
	ft_putstr(number);
	size = ft_strlen(number);
	return (size);
}