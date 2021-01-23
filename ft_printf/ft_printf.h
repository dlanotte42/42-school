/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:25:22 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/23 17:41:46 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdio.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_numlen(unsigned int num);
int		ft_strlen(char *str);
int		ft_iprintf(int numb);
int		ft_sprintf(char *str);
int		ft_cprintf(char letter);
int		ft_uprintf(unsigned int numb);
int		ft_calc_percent(char *str);
char	*ft_itoa(int num);
char    *ft_unsigned_itoa(unsigned int num);
int		ft_isalnum(int c);

#endif