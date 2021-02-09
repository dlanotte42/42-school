/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:47:34 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/09 18:53:24 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		*ft_fill_asterisk(va_list *list, int *result, int t_asterisk)
{
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(int) * (t_asterisk + 1))))
		return ((int *)NULL);
	result[t_asterisk + 1] = '\0';
	while (i < t_asterisk)
		result[i++] = va_arg(*list, int);
	return (result);
}

int				*ft_check_asterisk(va_list *list, char *str)
{
	int		*result;
	int		i;
	int		j;
	int		t_asterisk;

	j = 0;
	i = 0;
	t_asterisk = 0;
	while (str[i])
	{
		if (str[i++] == '%')
		{
			j = i - 1;
			while (!ft_is_parameter(str[++j]))
			{
				if (str[j] == '*' && str[j - 1] == '.')
					t_asterisk++;
				else if (str[j] == '*' && str[j - 1] != '*')
					t_asterisk++;
			}
		}
	}
	if (!(result = ft_fill_asterisk(list, result, t_asterisk)))
		return ((int *)NULL);
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
