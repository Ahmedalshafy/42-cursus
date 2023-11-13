/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:02:21 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/12 12:17:19 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	if (!new || !lst)
		return ;
	if (!(*(lst)))
	{
		*lst = new;
		return ;
	}
	n = *lst;
	while (n->next != NULL)
		n = n->next;
	n->next = new;
}
