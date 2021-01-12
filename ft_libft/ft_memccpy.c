/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:17:11 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/12 17:04:57 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *pointer;

	pointer = ft_memchr(src, c, n);
	if (pointer == NULL)
	{
		ft_memcpy(dst, src, n);
		return (dst);
	}
	ft_memcpy(dst, src, pointer - src + 1);
	return (dst);
}
