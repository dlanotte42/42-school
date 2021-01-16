/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:41:26 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/16 17:33:06 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		check(const char check, const char *set)
{
	const char	*p_s;

	p_s = set;
	while (*p_s)
	{
		if (check == *p_s)
			return (1);
		p_s++;
	}
	return (0);
}

size_t	ft_start_world_count(char const *s1, const char *set)
{
	size_t		start_word_counter;
	size_t		i;

	i = 0;
	start_word_counter = 0;
	while (s1[i])
	{
		if (!check(s1[i], set))
			break ;
		start_word_counter++;
		i++;
	}
	return (start_word_counter);
}

size_t	ft_end_word_counter(char const *s1, const char *set, size_t start)
{
	size_t		len;
	size_t		end_word_counter;

	end_word_counter = 0;
	len = ft_strlen(s1) - 1;
	while (len && len > start)
	{
		if (!check(s1[len], set))
			break ;
		end_word_counter++;
		len--;
	}
	return (end_word_counter);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t		i;
	size_t		k;
	char		*new_str;
	size_t		start_word_counter;
	size_t		end_word_counter;

	if (!s1)
		return (NULL);
	k = 0;
	start_word_counter = ft_start_world_count(s1, set);
	end_word_counter = ft_end_word_counter(s1, set, start_word_counter);
	i = start_word_counter + end_word_counter;
	new_str = malloc(sizeof(char) * (ft_strlen(s1) - i) + 1);
	if (!new_str)
		return (NULL);
	i = start_word_counter;
	while (i >= start_word_counter && i < (ft_strlen(s1) - end_word_counter))
	{
		new_str[k] = s1[i];
		i++;
		k++;
	}
	new_str[k] = '\0';
	return (new_str);
}
