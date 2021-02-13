/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 08:29:33 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/12 20:30:50 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			*ft_fill(va_list *list, int *result, int t_asterisk)
{
	int							i;

	i = 1;
	if (!(result = malloc(sizeof(int) * (t_asterisk + 2))))
		return ((int *)NULL);
	while (i < (t_asterisk + 1))
	{
		result[i] = va_arg(*list, int);
		i++;
	}
	return (result);
}

int			ft_percent(char *str, char *ori_string, int i, int *aster)
{
	int							printed;
	t_param						params;
	bool						alloc;

	alloc = false;
	printed = 0;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i + 1, '%');
	params.type = 's';
	if (!str)
	{
		alloc = true;
		str = return_null();
		if (params.asterisk_value[0] == '-')
			params.precision = false;
	}
	params = ft_check_params(params, str, 's');
	printed += ft_width(params, str);
	if (alloc)
		free(str);
	return (printed);
}

int			ft_find_numb(char *str, int i)
{
	int							len;
	int							number;
	char						*number_char;

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
