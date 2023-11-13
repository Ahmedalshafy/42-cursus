/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:59:06 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/12 14:34:16 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	n;
	int	i;

	if (s == 0)
		return (0);
	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		else
			i++;
	}
	return (n);
}

static char	*ex_words(char const *s, char *new, char c, int *i)
{
	int		j;

	while (s[*i] != 0)
	{
		j = 0;
		while (s[*i] != c && s[*i] != 0)
		{
			j++;
			(*i)++;
		}
		if (j > 0)
		{
			new = ft_substr(s, *i - j, j);
			return (new);
		}
		else
			(*i)++;
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**ary;
	int		i;
	int		ind;

	ary = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ary == 0)
		return (NULL);
	i = 0;
	ind = 0;
	while (s[i] != 0)
	{
		ary[ind] = ex_words(s, ary[ind], c, &i);
		if (ary[ind] != NULL && ind < count_words(s, c))
			ind++;
		else if (ary[ind] == NULL && ind < count_words(s, c))
		{
			while (--ind >= 0)
				free(ary[ind]);
			free(ary);
			return (NULL);
		}
	}
	ary[ind] = 0;
	return (ary);
}
