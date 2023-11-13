/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:03:30 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:40 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	int		start;
	int		end;

	if (s == 0)
		return (NULL);
	if (set == 0)
		return (ft_strdup(s));
	start = 0;
	end = ft_strlen(s) - 1;
	while (ft_strchr(set, s[start]) && s[start])
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s[end]) && end >= 0)
		end--;
	i = end + 1 - start;
	return (ft_substr(s, start, i));
}
