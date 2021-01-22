/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:16:08 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/22 16:16:09 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"


int		ft_printf(const char *str, ...)
{
	int			size;
	va_list		variables;
	int			i;
	int 		add;
	int			remove;

	i = 0;
	add = 0;
	va_start(variables, str);
	while (str[i])
	{
		if (str[i] == '%'&& str[i + 1] == 'd')
			add = add + ft_iprintf(va_arg(variables, int));
		//else if (str[i] == '%'&& str[i + 1] == 'c')
			//ft_cprintf();
		else
			ft_putchar(str[i]);
		if (str[i] == '%')
			i += 2;
		else
			i++;
	}
	va_end(variables);
	size = ft_strlen((char *)str);
	printf("SIZE: %d\n", size);
	printf("REMOVE: %d\n", remove = ft_calc_percent((char *)str));
	printf("ADD: %d\n", add);
	return ((size - remove) + add);
}

int	main(void)
{
	int Numero = 50006;

	printf("MY PRINTF: %d\n", ft_printf("Ciao %d %d %d %d Mondo\n", Numero, Numero, Numero, Numero));
	printf("OR PRINTF: %d", printf("Ciao %d %d %d %d Mondo\n",  Numero, Numero, Numero, Numero));

	return (0);
}
