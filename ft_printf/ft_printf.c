/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:19:54 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/02/11 19:36:36 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_s_switcher(char *str, int i, va_list *var)
{
	int				pr_c;
	int				*ast;

	pr_c = 0;
	ast = ft_check_asterisk(var, (char *)str, i);
	if (str[ft_c_par(str, i)] == 'd')
		pr_c = pr_c + ft_ip(va_arg(*var, int), (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 's')
		pr_c = pr_c + ft_sp(va_arg(*var, char *), (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 'c')
		pr_c = pr_c + ft_cp(va_arg(*var, int), (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 'u')
		pr_c = pr_c + ft_up(va_arg(*var, unsigned int), (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 'i')
		pr_c = pr_c + ft_ii_p(va_arg(*var, int), (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 'p')
		pr_c = pr_c + ft_p(*var, (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 'x')
		pr_c = pr_c + ft_hex_x(*var, (char *)str, i, ast);
	else if (str[ft_c_par(str,i)] == 'X')
		pr_c = pr_c + ft_hex_X(*var, (char *)str, i, ast);
	free(ast);
	return (pr_c);
}

static int	ft_switcher(char *str, int i, va_list *variables)
{
	int				pr_c;

	pr_c = 0;
	if (str[i] == '%' && str[i + 1] != '%')
		pr_c += ft_s_switcher(str, i, variables);
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
	return (pr_c);
}

int			ft_printf(const char *str, ...)
{
	va_list		variables;
	va_list		*variables_p;
	int			i;
	int			pr_c;

	i = 0;
	pr_c = 0;
	variables_p = &variables;
	va_start(variables, str);
	while (str[i])
	{
		pr_c += ft_switcher((char *)str, i, variables_p);
		i += ft_skip_content((char *)str, i);
	}
	va_end(variables);
	return (pr_c);
}

bool		ft_cc_pr(char *str, int i)
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
			if (str[i] == '%' && str[i - 1] == '%' && str[i - 2] == '%')
				return (false);
			if (str[i] == '%' && str[i - 1] == '%')
				return (true);
			if (str[i] == '%')
				return (false);
			else if (ft_is_parameter(str[i]))
				return (true);
		}
	}
	return (true);
}

int			ft_skip_content(char *str, int i)
{
	int			skip;

	skip = 1;
	if (str[i] == '%' && str[i + 1] == '%')
		return (2);
	if (str[i] != '%')
		return (1);
	while (str[i + skip] && !ft_is_parameter(str[i + skip]))
		skip++;
	return (skip);
}
