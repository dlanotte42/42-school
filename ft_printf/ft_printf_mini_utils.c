/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mini_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:18:03 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/30 19:13:56 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char *return_parameter()
{
  char *parameter;
  //cspdiuxX%
  if (!(parameter = malloc(sizeof(char) * 10)))
    return (NULL);
  parameter[0] = 'c';
  parameter[1] = 's';
  parameter[2] = 'p';
  parameter[3] = 'd';
  parameter[4] = 'i';
  parameter[5] = 'u';
  parameter[6] = 'x';
  parameter[7] = 'X';
  parameter[8] = '%';
  parameter[9] = '\0';
  return (parameter);
}

static char *return_flags()
{
  char *flags;
  //-0.*
  if (!(flags = malloc(sizeof(char) * 5)))
    return (NULL);
  flags[0] = '-';
  flags[1] = '0';
  flags[2] = '.';
  flags[3] = '*';
  flags[4] = '\0';
  return (flags);
}

char      ft_is_parameter(char c)
{
  static char *parameter;
  char *p_to_parameter;
  
  if (!parameter)
    parameter = return_parameter();
  p_to_parameter = parameter;
  while(*p_to_parameter)
  {
    if (c == *p_to_parameter)
      return(*p_to_parameter);
    p_to_parameter++;
  }
  return (0);
}

char   ft_is_flag(char c)
{
  static char *flags;
  char *p_to_flags;
  
  if (!flags)
    flags = return_flags();
  p_to_flags = flags;
  while(*p_to_flags)
  {
    if (c == *p_to_flags)
      return(*p_to_flags);
    p_to_flags++;
  }
  return (0);
}

int   ft_calc_paramenter(const char *str, int i)
{
  char parameter;

  while(str[i++])
  {
    if ((parameter = ft_is_flag(str[i])))
    {
      ft_putstr("TROVATO PARAMETRO: " );
      ft_putchar(parameter);
      ft_putchar('\n');
    }
    if (ft_is_parameter(str[i]))
        return(i);
  }
  return (0);
}