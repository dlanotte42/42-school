/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:49:41 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/22 17:49:42 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_iprintf(int numb)
{
	int size;
	char *number;
	
	number = ft_itoa(numb);
	ft_putstr(number);
	size = ft_numlen(numb);
	return (size);
}

/*int		ft_cprintf(char c)
{

	return (size);
}*/

