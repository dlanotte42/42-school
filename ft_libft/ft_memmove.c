/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:53:02 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/13 17:38:37 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		counter;
	char		*p_src;
	char		*p_dst;

	counter = 0;
	p_src = (char *)src;
	p_dst = (char *)dst;
	if (dst > src)
	{
		while (len)
		{
			len--;
			*(p_dst + len) = *(p_src + len);
		}
	}
	else
	{
		while (counter != len)
		{
			*(p_dst + counter) = *(p_src + counter);
			counter++;
		}
	}
	return (dst);
}
