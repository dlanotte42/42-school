/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:41:46 by dlanotte          #+#    #+#             */
/*   Updated: 2021/02/02 16:26:56 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

int		ft_printf(const char *str, ...);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_numlen(unsigned int num);
int		ft_strlen(char *str);
int		ft_ip(int numb);
int		ft_sp(char *str, char *original_string, int i);
int		ft_cp(char letter);
int		ft_up(unsigned int numb);
int   	ft_c_par(const char *str, int i);
char	*ft_itoa(int num);
char    *ft_unsigned_itoa(unsigned int num);
char   	ft_is_flag(char c);
char    ft_is_parameter(char c);
bool	ft_cc_pr(char *str, int i);

#endif