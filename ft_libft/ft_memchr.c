/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:53:43 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/12 15:08:43 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pointer;

	pointer = (unsigned char*)s;
	while (n)
	{
		if (*pointer != (unsigned char)c)
			pointer++;
		else
			return (pointer);
		n--;
	}
	return (NULL);
}
