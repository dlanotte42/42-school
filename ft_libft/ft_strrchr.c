/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:45:03 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/13 19:55:29 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrcchr(const char *s, int c)
{
        char    *p_s;
        size_t  len;

        p_s =  (char *)s;
        len = ft_strlen(s);
        p_s = p_s + len-1;
        while(*p_s)
        {
                if(*p_s == (char) c)
                        return (p_s);
                p_s--;
        }
        return (NULL);
}
