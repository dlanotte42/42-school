/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:11:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/19 16:06:15 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**occurences(char const *s, char c, size_t *size)
{
	char	*pt;
	int		flag;

	*size = 1;
	pt = (char *)s;
	flag = 1;
	while (*pt)
	{
		if (*pt != c && flag)
		{
			(*size)++;
			flag = 0;
		}
		else if (*pt == c && !flag)
		{
			flag = 1;
		}
		pt++;
	}
	return ((char**)malloc((*size) * sizeof(char *)));
}

static	char	*ft_copy(const char *src, size_t length)
{
	size_t	i;
	char	*dst;

	i = 0;
	if ((dst = (char*)malloc((length + 1) * sizeof(char))))
	{
		while (i < length)
		{
			dst[i] = src[i];
			i++;
		}
		dst[length] = '\0';
		return (dst);
	}
	return (NULL);
}

static	void	fill(char **array, char const *s, char c, size_t size)
{
	size_t	length;
	int		flag;
	int		i;
	char	*pt;

	i = 0;
	pt = (char *)s;
	flag = 1;
	length = 0;
	while (*pt)
	{
		if (*pt != c && flag)
			flag = 0;
		else if (*pt == c && !flag)
		{
			flag = 1;
			array[i] = ft_copy(pt - length, length);
			length = 0;
			i++;
		}
		length += (*pt != c);
		pt++;
	}
	if (length)
		array[size - 2] = ft_copy(pt - length, length);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (NULL);
	array = occurences(s, c, &size);
	if (!array)
		return (NULL);
	fill(array, s, c, size);
	array[size - 1] = NULL;
	return (array);
}
