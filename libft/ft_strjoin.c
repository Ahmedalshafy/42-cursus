/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:54:00 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/09 12:54:26 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *) malloc(s1len + s2len + 1);
	if (new == 0)
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
