/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:41:46 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/10 20:01:17 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_param
{
	bool	zero;
	bool	asterisk;
	bool	precision;
	bool	minus;
	bool	is_neg;
	bool	d_zero;
	int		width;
	int		precisions;
	int		*asterisk_value;
	char	type;
	char	r_type;
}				t_param;

t_param			ft_set_pa(t_param parameters, char *str, int i, char checked);
int				ft_find_numb(char *str, int i);
int				ft_atoi(char *str);
int				ft_printf(const char *str, ...);
int				ft_skip_content(char *str, int i);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_putstr(char *str);
int				ft_calc_width(char *str, int i, t_param params);
int				ft_calc_precision(char *str, int i, t_param params);
int				ft_putchar(char c);
int				ft_numlen(unsigned int num);
int				ft_strlen(char *str);
int				ft_ip(int numb, char *ori_string, int i, int *asterisk);
int				ft_ii_p(int numb, char *ori_string, int i, int *aster);
int				ft_p(va_list item, char *ori_string, int i, int *aster);
int				ft_sp(char *str, char *ori_string, int i, int *asterisk);
int				ft_cp(char letter, char *ori_string, int i, int *asterisk);
int				ft_up(unsigned int numb, char *ori_string, int i, int *asteri);
int				ft_c_par(const char *str, int i);
int				t_precision(t_param params, char *str);
int				ft_width(t_param params, char *str);
int				*ft_check_asterisk(va_list *list, char *str, int i);
char			*ft_itoa(int num);
char			*ft_unsigned_itoa(unsigned int num);
char			*return_null();
char			ft_is_flag(char c);
char			ft_is_parameter(char c);
bool			ft_cc_pr(char *str, int i);

#endif
