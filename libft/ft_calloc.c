/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:27:38 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/11 19:36:32 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
