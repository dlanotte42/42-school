/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:41:46 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/30 19:21:58 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdio.h>

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_numlen(unsigned int num);
int		ft_strlen(char *str);
int		ft_iprintf(int numb);
int		ft_sprintf(char *str, char *original_string, int i);
int		ft_cprintf(char letter);
int		ft_uprintf(unsigned int numb);
int		ft_calc_percent(char *str);
int   	ft_calc_paramenter(const char *str, int i);
char	*ft_itoa(int num);
char    *ft_unsigned_itoa(unsigned int num);
char   	ft_is_flag(char c);
char    ft_is_parameter(char c);

#endif