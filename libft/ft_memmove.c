/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:13:23 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/10 09:10:50 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!dst && !src)
		return (0);
	temp1 = (unsigned char *)src;
	temp2 = (unsigned char *)dst;
	if (temp2 > temp1)
	{
		i = n;
		while (i--)
			temp2[i] = temp1[i];
	}
	else
		ft_memcpy(temp2, temp1, n);
	return (dst);
}
