/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:04:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/29 18:11:59 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		variables;
	int			i;
	int			printed;

	i = 0;
	printed = 0;
	va_start(variables, str);
	while (str[i])
	{
		if (str[i] == '%'&& ((str[ft_calc_paramenter(str, i)] == 'd') || str[ft_calc_paramenter(str,i)] == 'i'))
			printed = printed + ft_iprintf(va_arg(variables, int));
		else if (str[i] == '%'&& str[ft_calc_paramenter(str,i)] == 's')
			printed = printed + ft_sprintf(va_arg(variables, char *));
		else if (str[i] == '%'&& str[ft_calc_paramenter(str,i)] == 'c')
			printed = printed + ft_cprintf(va_arg(variables, int));
		else if (str[i] == '%'&& str[ft_calc_paramenter(str,i)] == 'u')
			printed = printed + ft_uprintf(va_arg(variables, unsigned int));
		else
			if(str[i] != '%' || ((str[i]) == '%' && str[i + 1] == '%'))
				printed = printed + ft_putchar(str[i]);

		if (str[i] == '%' && ((ft_isalnum((int)str[i + 1])) || (str[i] == '%')))
			i += 2;
		else
			i++;
	}
	va_end(variables);
	return (printed);
}

int	main(void)
{
	int				DEBUG = 1;


	char			Author[] = "zxcvbinz";
	char			Lettera = 'Z';
	int 			Numero = 50006;
	char			NumeroChar[] = "100012";
	//char			*lett_p;
	unsigned int	int_u = 4294967295;

	//lett_p = &Lettera;

	//ft_printf("%%");


	//ft_printf("MY PRINTF: %d\n", ft_printf("unsigned int: %u\n", int_u));
	if (DEBUG)
	{
		ft_printf("NUM: %d\n", ft_printf("\n||||||MY VERSION||||||\nCiao Mondo, io mi chiamo %s\n(%%)", Author));
		ft_printf("MY PRINTF: %d\n", ft_printf("ID: %c(c) Test by %s(s) %i(i) + %d(d) = %s(s) unsigned int: %u(u)\n", Lettera, Author, Numero, Numero, NumeroChar, int_u));
	 
		printf("ORI: %d\n", printf("\n||||||OR VERSION||||||\nCiao Mondo, io mi chiamo %s\n(%%)", Author));
		printf("OR PRINTF: %d\n\n", printf("ID: %c(c) Test by %s(s) %i(i) + %d(d) = %s(s) unsigned int: %u(u)\n", Lettera, Author, Numero, Numero, NumeroChar, int_u));
	}
	return (0);
}




/*

COPY TO ONLINE IDE

#include <stdio.h>

static    int        ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char *return_paramater()
{
  char *parameter;
  
  parameter = malloc();
  
  
}






int                ft_calc_paramenter(const char *str, int i)
{
    while(str[i++])
    {
      if ft_calc_flags(str[i]);
        if (ft_isalpha(str[i]))
            return(i);
    }
    return (0);
}

int ft_printf(char *str, int test)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] == '%' && ((str[ft_calc_paramenter(str, i)] == 'd') || str[ft_calc_paramenter(str,i)] == 'i'))
      printf("Trovato numero");
    i++;
  }





  return (100);
}

int main(void)
{
    int ciao = 130;
  
    ft_printf("%10d", ciao);
    printf("%10d", ciao);
    
    
    
    return (0);
} */