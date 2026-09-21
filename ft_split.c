/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:12:24 by txu-sen           #+#    #+#             */
/*   Updated: 2026/08/04 16:27:38 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	n_word;

	count = 0;
	n_word = 0;
	while (*s)
	{
		if (*s != c && !n_word)
		{
			n_word = 1;
			count++;
		}
		else if (*s == c)
			n_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_dup_word(const char *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **result, int j)
{
	while (j > 0)
		free(result[--j]);
	free(result);
	return (NULL);
}

static char	**ft_fill_split(char **result, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = ft_dup_word(s, start, i);
			if (!result[j])
				return (ft_free(result, j));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	return (ft_fill_split(result, s, c));
}
