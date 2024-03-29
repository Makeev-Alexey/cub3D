/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:32:43 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:18:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			counter;
	unsigned char	*dst_tmp;

	counter = 0;
	dst_tmp = (unsigned char *)dst;
	while (counter < n)
	{
		dst_tmp[counter] = c;
		counter++;
	}
	return (dst);
}
