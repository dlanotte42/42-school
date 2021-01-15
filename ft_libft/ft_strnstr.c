/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:56:20 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/15 17:05:52 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	tmph_len;

	h_len = 0;
	if (needle[h_len] == '\0')
		return ((char *)haystack);
	while (haystack[h_len] && h_len < len)
	{
		n_len = 0;
		tmph_len = h_len;
		while (haystack[h_len] == needle[n_len] && h_len < len)
		{
			h_len++;
			n_len++;
			if (needle[n_len] == '\0')
				return ((char *)&haystack[tmph_len]);
		}
		h_len = tmph_len;
		h_len++;
	}
	return (NULL);
}
