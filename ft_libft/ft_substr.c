/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:03:20 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/15 20:19:01 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!(str))
		return (NULL);
	sub = malloc(sizeof(*str) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = str[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
