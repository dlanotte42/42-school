/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:55:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/17 13:00:40 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*new_src;
	size_t	size;
	size_t	i;

	size = ft_strlen(src);
	new_src = malloc((size + 1) * sizeof(char));
	if (!new_src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}
