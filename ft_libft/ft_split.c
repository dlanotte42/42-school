/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:11:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/01/17 19:16:13 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

const char	*ft_fill(const char *s, char c, char **word_matrix, int i)
{
	int			j;

	j = 0;
	while (*s && *s != c)
	{
		word_matrix[i][j] = *s;
		s++;
		j++;
	}
	word_matrix[i][j] = '\0';
	while (*s == c && *s)
		s++;
	return (s);
}

int			ft_count_word(const char *s_fake, char **word_matrix, char c, int i)
{
	int			c_counter;

	c_counter = 0;
	while (*s_fake != c && *s_fake)
	{
		s_fake++;
		c_counter++;
	}
	if (!(word_matrix[i] = malloc(sizeof(char) * (c_counter + 1))))
		return ((int)NULL);
	return (c_counter);
}

char		**ft_allocate(const char *s, char c, char **word_matrix, int word)
{
	const char	*s_fake;
	int			i;
	int			j;
	int			c_counter;

	j = 0;
	i = 0;
	s_fake = s;
	while (i < word)
	{
		c_counter = ft_count_word(s_fake, word_matrix, c, i);
		j = 0;
		s = ft_fill(s, c, word_matrix, i);
		s_fake = s;
		while (*s_fake == c && *s_fake)
			s_fake++;
		i++;
	}
	return (word_matrix);
}

char		**ft_split(char const *s, char c)
{
	char		**word_matrix;
	int			word;
	const char	*p_s;
	int			numb_word;

	word = 0;
	if (!s)
		return (NULL);
	if (*s != c)
		word = 1;
	p_s = s;
	numb_word = word;
	while (*p_s)
	{
		if (*p_s != c && *(p_s - 1) == c)
			numb_word++;
		p_s++;
	}
	while (*s == c && *s)
		s++;
	if (!(word_matrix = malloc(sizeof(char *) * numb_word + 1)))
		return (NULL);
	word_matrix = ft_allocate(s, c, word_matrix, numb_word);
	word_matrix[numb_word] = NULL;
	return (word_matrix);
}
