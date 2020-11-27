/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 01:22:05 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:15:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
		counter++;
	}
	return (0);
}
