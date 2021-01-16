/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:01:43 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/16 15:05:38 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = 0;
	s2_len = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new_str)
		return (NULL);
	while (s1[s1_len])
	{
		new_str[s1_len] = s1[s1_len];
		s1_len++;
	}
	while (s2[s2_len])
	{
		new_str[s2_len + s1_len] = s2[s2_len];
		s2_len++;
	}
	new_str[s2_len + s1_len] = '\0';
	return (new_str);
}
