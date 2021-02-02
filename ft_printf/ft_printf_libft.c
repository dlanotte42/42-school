/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:17:53 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/02 16:24:27 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_fill_table(char *n_con, int size, int num, int is_n)
{
	n_con[size] = '\0';
	while (size)
	{
		if (is_n > 1)
		{
			n_con[size - 1] = (((num % 10) + 1) + 48);
			is_n = 1;
		}
		else
			n_con[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	return (n_con);
}

char			*ft_itoa(int num)
{
	int			size;
	int			is_n;
	char		*n_con;

	is_n = 0;
	if (num == -2147483648)
	{
		is_n = 2;
		num++;
		num = num * -1;
	}
	else if (num < 0)
	{
		is_n++;
		num = num * -1;
	}
	size = ft_numlen(num);
	if (is_n)
		size++;
	if (!(n_con = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_fill_table(n_con, size, num, is_n);
	if (is_n)
		n_con[0] = '-';
	return (n_con);
}

char			*ft_unsigned_itoa(unsigned int num)
{
	int			size;
	char		*n_con;

	size = ft_numlen(num);
	if (!(n_con = malloc(sizeof(char) * size + 1)))
		return (NULL);
	n_con[size] = '\0';
	while (size)
	{
		n_con[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	return (n_con);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}