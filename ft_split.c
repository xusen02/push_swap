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

static int	wordcount(char const *str, char c)
{
	int	c1;
	int	flag;
	int	wc;

	c1 = 0;
	flag = 1;
	wc = 0;
	while (str[c1])
	{
		if (str[c1] == c)
			flag = 1;
		else if (flag)
		{
			flag = 0;
			wc++;
		}
		c1++;
	}
	return (wc);
}

static void	free_all(char **barr, int c)
{
	while (c > 0)
		free(barr[--c]);
	free(barr);
}

static char	*wordcpy(char const *str, char c)
{
	char	*to_return;
	int		len;

	len = 0;
	while (str[len] && !(str[len] == c))
		len++;
	to_return = malloc(sizeof(char) * (1 + len));
	if (!to_return)
		return (NULL);
	to_return[len] = '\0';
	while (len > 0)
	{
		to_return[len - 1] = str[len - 1];
		len--;
	}
	return (to_return);
}

char	**ft_split(char const *str, char c)
{
	int		count;
	char	**barr;

	if (!str)
		return (NULL);
	barr = malloc(sizeof(char *) * (1 + wordcount(str, c)));
	if (barr == NULL)
		return (NULL);
	count = 0;
	while (*str)
	{
		if (!(*str == c))
		{
			barr[count] = wordcpy(str, c);
			if (!barr[count])
				return (free_all(barr, count), (NULL));
			count++;
			while (*str && !(*str == c))
				str++;
		}
		else
			str++;
	}
	barr[count] = NULL;
	return (barr);
}
