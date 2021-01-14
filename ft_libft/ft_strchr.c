/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:27:52 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/14 19:49:26 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *p_s;

	p_s = (char *)s;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*p_s)
	{
		if (*p_s == (char)c)
			return (p_s);
		p_s++;
	}
	return (NULL);
}
