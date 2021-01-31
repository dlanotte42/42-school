/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mini_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:18:03 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/31 19:04:19 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*return_parameter(void)
{
	char		*parameter;

	if (!(parameter = malloc(sizeof(char) * 10)))
		return (NULL);
	parameter[0] = 'c';
	parameter[1] = 's';
	parameter[2] = 'p';
	parameter[3] = 'd';
	parameter[4] = 'i';
	parameter[5] = 'u';
	parameter[6] = 'x';
	parameter[7] = 'X';
	parameter[8] = '%';
	parameter[9] = '\0';
	return (parameter);
}

static char		*return_flags(void)
{
	char		*flags;

	if (!(flags = malloc(sizeof(char) * 5)))
		return (NULL);
	flags[0] = '-';
	flags[1] = '0';
	flags[2] = '.';
	flags[3] = '*';
	flags[4] = '\0';
	return (flags);
}

char			ft_is_parameter(char c)
{
	static char *parameter;
	char		*p_to_parameter;

	if (!parameter)
		parameter = return_parameter();
	p_to_parameter = parameter;
	while (*p_to_parameter)
	{
		if (c == *p_to_parameter)
			return (*p_to_parameter);
		p_to_parameter++;
	}
	return (0);
}

char			ft_is_flag(char c)
{
	static char	*flags;
	char		*p_to_flags;

	if (!flags)
		flags = return_flags();
	p_to_flags = flags;
	while (*p_to_flags)
	{
		if (c == *p_to_flags)
			return (*p_to_flags);
		p_to_flags++;
	}
	return (0);
}

int				ft_c_par(const char *str, int i)
{
	char	parameter;

	while (str[i++])
	{
		if (ft_is_parameter(str[i]))
			return (i);
	}
	return (0);
}
