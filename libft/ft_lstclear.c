/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:02:21 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/12 14:12:02 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;

	if (!lst || !*lst || !del)
		return ;
	n = *lst;
	while (lst != NULL && *lst != NULL)
	{
		n = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = n;
	}
}
