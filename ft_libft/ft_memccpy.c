/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:17:11 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/15 16:57:27 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;
	size_t			i;

	i = 0;
	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	while (i < n)
	{
		tmpd[i] = tmps[i];
		if (tmps[i] == (unsigned char)c)
			return ((void *)&tmpd[i + 1]);
		i++;
	}
	return (NULL);
}
