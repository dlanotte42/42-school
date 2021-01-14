/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:56:20 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/14 19:03:52 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (needle == NULL || ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) > len)
		return (NULL);
	while (i < len)
	{
		if (ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
