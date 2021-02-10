/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:47:34 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/10 20:01:38 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		*ft_fill(va_list *list, int *result, int t_asterisk)
{
	int							i;

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

int				ft_find_numb(char *str, int i)
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

static char			*ft_foundpointer(long unsigned int i)
{
	int						j;
	int						k;
	int						arr[16];
	char					*str;

	k = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * 17)))
		return (NULL);
	while (i > 0)
	{
		arr[j] = i % 16;
		i = i / 16;
		j++;
	}
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

int				ft_p(va_list item, char *ori_string, int i, int *aster)
{
	char					*str;
	int						printed;
	t_param					params;
	long unsigned int		numb;

	numb = va_arg(item, long unsigned int);
	printed = 0;
	params.is_neg = false;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i, 'd');
	params.r_type = 'p';
	str = ft_foundpointer(numb);
	if (params.precision && params.precisions >= ft_strlen(str))
		params.width -= params.precisions;
	else if (params.precisions <= ft_strlen(str) && params.precision && numb)
	{
		params.precisions = 0;
		params.precision = false;
		params.zero = false;
	}
	if (!params.precision)
		params.width -= ft_strlen(str);
	printed += ft_width(params, str);
	free(str);
	return (printed);
}
