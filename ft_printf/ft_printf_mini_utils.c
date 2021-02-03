/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mini_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:18:03 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/03 18:09:14 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*return_parameter(void)
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

char		*return_flags(void)
{
	char		*flags;

	if (!(flags = malloc(sizeof(char) * 4)))
		return (NULL);
	flags[0] = '-';
	flags[1] = '.';
	flags[2] = '*';
	flags[3] = '\0';
	return (flags);
}

char		ft_is_parameter(char c)
{
	char		return_value;
	char		*parameter;
	int			i;

	i = 0;
	parameter = return_parameter();
	while (parameter[i])
	{
		if (c == parameter[i])
		{
			return_value = parameter[i];
			free(parameter);
			return (return_value);
		}
		i++;
	}
	free(parameter);
	return (0);
}

char		ft_is_flag(char c)
{
	char		*flags;
	int			i;
	char		return_value;

	i = 0;
	flags = return_flags();
	while (flags[i])
	{
		if (c == flags[i])
		{
			return_value = flags[i];
			free(flags);
			return (return_value);
		}
		i++;
	}
	free(flags);
	return (0);
}

int			ft_c_par(const char *str, int i)
{
	char		parameter;

	while (str[i++])
	{
		if (ft_is_parameter(str[i]))
			return (i);
	}
	return (0);
}
