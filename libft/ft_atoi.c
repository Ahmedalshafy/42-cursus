/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:09 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/12 14:24:38 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	n;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != 0 && *str >= 48 && *str <= 57)
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	if (n >= 9223372036854775807ULL && sign == 1)
		return (-1);
	if (n >= 9223372036854775808ULL && sign == -1)
		return (0);
	return (n * sign);
}

// int main(int argc, char **argv)
// {
//     printf("orig fun: %i\n", atoi(argv[1]));
//     printf("new  fun: %i\n", ft_atoi(argv[1]));
// }