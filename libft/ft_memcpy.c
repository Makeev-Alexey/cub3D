/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:36:28 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:12:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t			runner;
	unsigned char	*src;
	unsigned char	*dst;

	runner = 0;
	if (!(destination) && !(source))
		return (NULL);
	src = (unsigned char *)source;
	dst = (unsigned char *)destination;
	while (runner < n)
	{
		dst[runner] = src[runner];
		runner++;
	}
	return (destination);
}
