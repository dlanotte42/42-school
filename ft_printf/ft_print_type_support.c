/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_support.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:27:32 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/04 19:43:30 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_calc_width(char *str, int i, t_param params)
{
	while (str[i++] != params.type)
		if (ft_isdigit(str[i]) && str[i] != '0')
			if (str[i - 1] != '.')
				return (ft_find_numb(str, i));
	return (0);
}

int				ft_calc_precision(char *str, int i, t_param params)
{
	if (ft_isdigit(str[i + 1]))
		return (ft_find_numb(str, i + 1));
	return (0);
}

// Ricorati di togliere questa merda
static char		*ft_add_zeros(char *str, t_param params, char *string)
{
	int		zeros;
	int		i;
	int		j;

	i = -1;
	zeros = 0;
	j = 0;
	if (params.precision)
	{
		if (params.width > params.precisions)
			zeros = (params.width - params.precisions) + 1;
	}
	else if (!params.precision)
		if (params.width > ft_strlen(string))
			zeros = (params.width - ft_strlen(string)) + 1;
	if (params.zero)
		while (zeros--)
			str[i++] = '0';
	else if (!params.zero)
		while (zeros--)
			str[i++] = ' ';
	if (params.precision)
		while (params.precisions--)
			str[i++] = string[j++];
	return (str);
}
// Ricorati di togliere questa merda
char			*ft_create_string(char *str, t_param params)
{
	char	*new_str;
	int		t_size;

	t_size = 0;
	if (params.width > ft_strlen(str))
		t_size = params.width;
	if (params.precision && params.precisions > params.width)
		t_size = params.precisions;
	if (params.precision && params.precisions < params.width)
		t_size = params.width;
	if (!params.width && params.precision)
		t_size = params.precisions;
	if (!t_size)
		t_size = ft_strlen(str);
	if (!(new_str = malloc(sizeof(char) * (t_size + 1))))
		return (NULL);
	new_str[t_size + 1] = '\0';
	new_str = ft_add_zeros(new_str, params, str);
	if (t_size && new_str[t_size - 1] != '\0')
		return (new_str);
	return (str);
}
// Ricorati di togliere questa merda
