/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:04:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/23 18:24:05 by dlanotte         ###   ########.fr       */
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
		if (str[i] == '%'&& ((str[i + 1] == 'd') || str[i + 1] == 'i'))
			add = add + ft_iprintf(va_arg(variables, int));
		else if (str[i] == '%'&& str[i + 1] == 's')
			add = add + ft_sprintf(va_arg(variables, char *));
		else if (str[i] == '%'&& str[i + 1] == 'c')
			add = add + ft_cprintf(va_arg(variables, int));
		else if (str[i] == '%'&& (str[i + 1] == 'u'))
			add = add + ft_uprintf(va_arg(variables, unsigned int));
		else
			ft_putchar(str[i]);


		if (str[i] == '%' && ft_isalnum((int)str[i + 1]))
			i += 2;
		else
			i++;
	}
	va_end(variables);
	size = ft_strlen((char *)str);
	remove = ft_calc_percent((char *)str);
	//printf("SIZE: %d\n", size);
	//printf("REMOVE: %d\n", remove);
	//printf("ADD: %d\n", add);
	return ((size - remove) + add);
}

int	main(void)
{
	char			Author[] = "zxcvbinz";
	char			Lettera = 'Z';
	int 			Numero = 50006;
	char			NumeroChar[] = "100012";
	//char			*lett_p;
	unsigned int	int_u = 4294967295;

	//lett_p = &Lettera;

	//ft_printf("MY PRINTF: %d\n", ft_printf("unsigned int: %u\n", int_u));

	ft_printf("NUM: %d\n", ft_printf("\n||||||MY VERSION||||||\nCiao Mondo, io mi chiamo %s\n", Author));
	ft_printf("MY PRINTF: %d\n", ft_printf("ID: %c(c) Test by %s(s) %i(i) + %d(d) = %s(s) unsigned int: %u(u)\n", Lettera, Author, Numero, Numero, NumeroChar, int_u));

	printf("ORI: %d\n", printf("\n||||||OR VERSION||||||\nCiao Mondo, io mi chiamo %s\n", Author));
	printf("OR PRINTF: %d\n\n", printf("ID: %c(c) Test by %s(s) %i(i) + %d(d) = %s(s) unsigned int: %u(u)\n", Lettera, Author, Numero, Numero, NumeroChar, int_u));

	return (0);
}