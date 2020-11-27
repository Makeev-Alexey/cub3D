/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 15:00:36 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:13:36 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*str;

	str = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (str[counter] == (unsigned char)c)
			return (&str[counter]);
		counter++;
	}
	return (NULL);
}
