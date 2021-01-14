/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:28:39 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/13 17:42:13 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_1;
	unsigned char	*p_2;

	p_1 = (unsigned char *)s1;
	p_2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*p_1 != *p_2)
			return (*p_1 - *p_2);
		i++;
		p_1++;
		p_2++;
	}
	return (0);
}
