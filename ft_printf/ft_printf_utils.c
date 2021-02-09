/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:19:13 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/09 12:38:29 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int printed;

	printed = 0;
	while (str[printed] != '\0')
		printed = printed + ft_putchar(str[printed]);
	return (printed);
}

int		ft_numlen(unsigned int num)
{
	int			size;

	size = 0;
	while (num > 9)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*return_null(void)
{
	char	*new_str;

	if (!(new_str = malloc(sizeof(char) * 7)))
		return (NULL);
	new_str[0] = '(';
	new_str[1] = 'n';
	new_str[2] = 'u';
	new_str[3] = 'l';
	new_str[4] = 'l';
	new_str[5] = ')';
	new_str[6] = '\0';
	return (new_str);
}
