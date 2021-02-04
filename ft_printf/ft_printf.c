/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:04:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/04 19:35:38 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


int		ft_printf(const char *str, ...)
{
	va_list		variables;
	int			i;
	int			pr_c;

	i = 0;
	pr_c = 0;
	va_start(variables, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			if ((str[ft_c_par(str, i)] == 'd') || str[ft_c_par(str,i)] == 'i')
				pr_c = pr_c + ft_ip(va_arg(variables, int));
			else if (str[ft_c_par(str,i)] == 's')
				pr_c = pr_c + ft_sp(va_arg(variables, char *), (char *)str, i);
			else if (str[ft_c_par(str,i)] == 'c')
				pr_c = pr_c + ft_cp(va_arg(variables, int));
			else if (str[ft_c_par(str,i)] == 'u')
				pr_c = pr_c + ft_up(va_arg(variables, unsigned int));
		}
		else
		{
			if (ft_cc_pr((char *)str, i) && str[i] == '%' && str[i + 1] == '%')
			{
				pr_c = pr_c + ft_putchar(str[i]);
				i++;
			}
			else if (ft_cc_pr((char *)str, i))
				pr_c = pr_c + ft_putchar(str[i]);
		}
		i += ft_skip_content((char *)str, i);
	}
	va_end(variables);
	return (pr_c);
}

bool	ft_cc_pr(char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%')
		return (true);
	else if (str[i] == ' ')
		return (true);
	else if (!ft_is_parameter(str[i]) && !ft_is_flag(str[i]))
		return (true);
	else
	{
		while (str[i--])
		{
			if (str[i] == '%')
				return (false);
			else if (ft_is_parameter(str[i]))
				return (true);
		}
	}
	return (true);
}

int		ft_skip_content(char *str, int i)
{
	int		skip;

	skip = 1;
	if (str[i] != '%')
		return (1);
	while (str[i + skip] && !ft_is_parameter(str[i + skip]))
		skip++;
	return (skip);
}

int	main(void)
{
	bool			DEBUG = false;
	bool			DEBUG_F = true;	
	char			Author[] = "zxcvbinz";
	char			Lettera = 'Z';
	int 			Numero = 50006;
	char			NumeroChar[] = "100012";
	unsigned int	int_u = 4294967295;

	if (DEBUG)
	{
		ft_printf("NUM: %d\n", ft_printf("iiii\n||||||MY VERSION||||||\nCiao Mondo, io mi chiamo %.0s\n(%%)", Author));
		ft_printf("MY PRINTF: %d\n", ft_printf("ID: %c(c) Test by %s(s) %i(i) + %d(d) = %s(s) unsigned int: %u(u) Controllo Flag=0*.\n", Lettera, Author, Numero, Numero, NumeroChar, int_u));
	 
		printf("ORI: %d\n", printf("iiii\n||||||OR VERSION||||||\nCiao Mondo, io mi chiamo %s\n(%%)", Author));
		printf("OR PRINTF: %d\n\n", printf("ID: %c(c) Test by %s(s) %i(i) + %d(d) = %s(s) unsigned int: %u(u) Controllo Flag=0*.\n", Lettera, Author, Numero, Numero, NumeroChar, int_u));
	}
	else if (DEBUG_F)
	{
		ft_printf("NUM: %d\n", ft_printf("TEST FLAG : %11.9s\n", Author));
		printf("\n");
		printf("OR: %d\n", printf("TEST FLAG : %11.9s\n", Author));
	}

	return (0);
}
