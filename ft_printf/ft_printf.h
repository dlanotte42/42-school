/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:36:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/22 16:36:26 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdio.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_numlen(int num);
int		ft_strlen(char *str);
int		ft_iprintf(int numb);
int		ft_calc_percent(char *str);
char	*ft_itoa(int num);

#endif