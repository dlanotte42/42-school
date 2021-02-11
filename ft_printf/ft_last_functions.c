/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:59:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/11 19:20:30 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static char			*fill_str_xX(char *str, int j, int arr[16], int type)
{
	int k;

	k = 0;
	while (j-- > 0)
    {
        if (arr[j] >= 0 && arr[j] <= 9)
            str[k] = arr[j] + '0';
        else if (arr[j] > 9)
		{
			if (type == 1)
            	str[k] = arr[j] + 'a' - 10;
			else if (type == 2)
				str[k] = arr[j] + 'A' - 10;
		}
        k++;
    }
	return (str);
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

char            *ft_foundhexadec(unsigned int i, int type)
{
    int j;
    int k;
    int arr[16];
    char *str;

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
	str = fill_str_xX(str, j, arr, type);
    return (str);
}

int				ft_hex_x(va_list item, char *ori_string, int i, int *aster)
{
	char					*str;
	int						printed;
	t_param					params;
	long unsigned int		numb;

	numb = va_arg(item, unsigned int);
	printed = 0;
	params.is_neg = false;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i, 'x');
	params.type = 'd';
	params.r_type = 'x';
	str = ft_foundhexadec(numb, 1);
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

int				ft_hex_X(va_list item, char *ori_string, int i, int *aster)
{
	char					*str;
	int						printed;
	t_param					params;
	long unsigned int		numb;

	numb = va_arg(item, unsigned int);
	printed = 0;
	params.is_neg = false;
	params.asterisk_value = aster;
	params = ft_set_pa(params, ori_string, i, 'X');
	params.type = 'd';
	params.r_type = 'X';
	str = ft_foundhexadec(numb, 2);
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