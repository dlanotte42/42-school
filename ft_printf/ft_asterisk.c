/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:47:34 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/10 00:19:05 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		*ft_fill_asterisk(va_list *list, int *result, int t_asterisk)
{
	int		i;

	i = 1;
	if (!(result = malloc(sizeof(int) * (t_asterisk + 2))))
		return ((int *)NULL);
	while (i < (t_asterisk + 1))
	{
		result[i] = va_arg(*list, int);
		if (result[i] < 0)
		{
			result[0] = '-';
			result[i] *= -1;
		}
		i++;
	}
	return (result);
}

int				*ft_check_asterisk(va_list *list, char *str, int i)
{
	int		*result;
	int		t_asterisk;

	t_asterisk = 0;
	i++;
	while(!ft_is_parameter(str[i]))
	{
		if (str[i] == '*' && str[i - 1] == '.')
			t_asterisk++;
		else if (str[i] == '*' && str[i - 1] != '*')
			if (str[i + 1] != '*')
				t_asterisk++;
		i++;
	}
	if (t_asterisk > 2)
		t_asterisk = 2;
	result = ft_fill_asterisk(list, result, t_asterisk);
	return (result);
}

int				ft_find_numb(char *str, int i)
{
	int						len;
	int						number;
	char					*number_char;

	len = 0;
	while (ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	if (!(number_char = malloc(sizeof(char) * (len + 1))))
		return ((int)NULL);
	i -= len;
	len = 0;
	while (ft_isdigit(str[i]))
	{
		number_char[len] = str[i];
		i++;
		len++;
	}
	number_char[len] = '\0';
	number = ft_atoi(number_char);
	free(number_char);
	return (number);
}
