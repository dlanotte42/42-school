/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:47:34 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/12 08:38:22 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					*ft_check_asterisk(va_list *list, char *str, int i)
{
	int							*result;
	int							t_asterisk;
	char						type;
	int							i_back;

	t_asterisk = 0;
	i_back = i;
	i++;
	while (!ft_is_parameter(str[i]))
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
	result = ft_fill(list, result, t_asterisk);
	return (result);
}

static char			*ft_s_ffpointer(char *str, long unsigned int i)
{
	if (i == 0)
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * 17)))
		return (NULL);
	return (str);
}

static char			*ft_ss_ffpointer(int j, int *arr, int k, char *str)
{
	while (j-- > 0)
	{
		if (arr[j] >= 0 && arr[j] <= 9)
			str[k] = arr[j] + '0';
		else if (arr[j] > 9)
			str[k] = arr[j] + 'a' - 10;
		k++;
	}
	str[k] = '\0';
	return (str);
}

static char			*ft_foundpointer(long unsigned int i)
{
	int							j;
	int							k;
	int							arr[16];
	char						*str;

	k = 0;
	j = 0;
	str = ft_s_ffpointer(str, i);
	if (str[0] == 48 && str[1] == '\0')
		return (str);
	while (i > 0)
	{
		arr[j] = i % 16;
		i = i / 16;
		j++;
	}
	str = ft_ss_ffpointer(j, arr, k, str);
	return (str);
}

int					ft_p(va_list item, char *ori_string, int i, int *aster)
{
	char						*str;
	int							printed;
	t_param						params;
	long unsigned int			numb;

	numb = va_arg(item, long unsigned int);
	printed = 0;
	params.is_neg = false;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i, 'p');
	params.type = 'd';
	params.r_type = 'p';
	str = ft_foundpointer(numb);
	params = ft_check_params(params, str, 'd');
	if (params.precisions <= ft_strlen(str) && params.precision && numb)
	{
		params.precisions = 0;
		params.precision = false;
		params.zero = false;
	}
	printed += ft_width(params, str);
	free(str);
	return (printed);
}
