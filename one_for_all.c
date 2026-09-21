/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_for_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:27:36 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/21 16:27:40 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
	{
		s++;
	}
	return ((size_t)(s - start));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i++] = ' ';
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**process_argv(char **argv_alpha)
{
	char	*temp_str;
	char	**to_return;
	int		c;

	temp_str = malloc(1);
	temp_str[0] = '\0';
	c = 0;
	while (argv_alpha[c])
		temp_str = ft_strjoin(temp_str, argv_alpha[c++]);
	to_return = ft_split(temp_str, ' ');
	free(temp_str);
	return (to_return);
}

int	count_argv(char **argv)
{
	int	c;

	c = 0;
	while (argv[c])
		c++;
	return (c);
}
