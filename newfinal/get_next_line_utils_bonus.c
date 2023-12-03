/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/02 14:26:27 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *) malloc(s1len + s2len + 1);
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	bytes;
	void	*p;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	p = malloc(bytes);
	if (!p)
		return (NULL);
	while (i < bytes)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}
