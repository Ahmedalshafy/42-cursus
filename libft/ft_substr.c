/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:51:42 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/12 14:25:40 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *) malloc(len + 1);
	if (sub == 0)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (i < len && s[start] != 0)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
	}
	sub[i] = 0;
	return (sub);
}

// int main()
// {
// 	char *str = "01234";
// 	size_t size = 10;
// 	char *ret = ft_substr(str, 10, size);
// 	char *ret2 = "";
// 	printf("%s\n", ret);
// 	printf("%s\n", ret2);

// }
