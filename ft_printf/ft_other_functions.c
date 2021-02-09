/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:08:59 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/09 19:08:22 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_atoi(char *str)
{
	int						is_negative;
	unsigned long long		result;

	result = 0;
	is_negative = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		is_negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		if (result >= 9223372036854775808ULL)
			return (is_negative == 1 ? -1 : 0);
		str++;
	}
	return ((int)result * is_negative);
}

static int		ft_zeros_count(int number)
{
	char					*number_str;
	int						t_zeros;
	int						i;

	i = 0;
	t_zeros = 0;
	number_str = ft_itoa(number);
	while (number_str[i])
	{
		if (number_str[i] == '0')
			t_zeros++;
		i++;
	}
	free(number_str);
	return (t_zeros);
}

static bool		ft_zeros_check(char *str, int i, t_param params)
{
	int						t_zeros;
	bool					precision_check;

	precision_check = false;
	t_zeros = 0;
	while (str[--i] != '%')
		if (ft_isdigit(str[i] && str[i - 1] == '.'))
			precision_check = true;
	while (str[i++] != params.type)
		if (str[i] == '0')
			t_zeros++;
		else if (str[i] == '.')
			break ;
	if (params.width > 0)
		t_zeros -= ft_zeros_count(params.width);
	if (params.precision && precision_check)
		t_zeros -= ft_zeros_count(params.precisions);
	if (t_zeros)
		return (true);
	return (false);
}

static t_param	ft_s_set_pa(t_param params, char *str, int i)
{
	static int counter;

	if (!counter)
		counter = 0;
	if (params.zero)
		params.zero = ft_zeros_check(str, i, params);
	if (params.minus)
		params.zero = false;
	while (str[i] != '%')
		i--;
	while (!ft_is_parameter(str[++i]))
	{
		if (str[i] == '*' && str[i - 1] == '.' && params.asterisk_value)
		{
			params.precision = true;
			params.precisions = params.asterisk_value[counter++];
		}
		else if (str[i] == '*' && str[i - 1] != '*')
			if (str[i + 1] != '*')
				params.width = params.asterisk_value[counter++];
	}
	return (params);
}

t_param			ft_set_pa(t_param parameters, char *str, int i, char checked)
{
	parameters.asterisk = false;
	parameters.minus = false;
	parameters.precision = false;
	parameters.zero = false;
	parameters.type = checked;
	parameters.width = ft_calc_width(str, i, parameters);
	while (str[i++] && str[i] != checked)
		if (str[i] == '.')
		{
			parameters.precision = true;
			parameters.precisions = ft_calc_precision(str, i, parameters);
		}
		else if (str[i] == '-')
			parameters.minus = true;
		else if (str[i] == '0' && parameters.width == 0)
			parameters.zero = true;
		else if (str[i] == '*')
			parameters.asterisk = true;
		else if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			parameters.zero = true;
	parameters = ft_s_set_pa(parameters, str, i);
	return (parameters);
}
