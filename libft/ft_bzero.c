/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:01:54 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:09:16 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*s1;

	counter = 0;
	s1 = (unsigned char *)s;
	while (counter < n)
	{
		s1[counter] = 0;
		counter++;
	}
}
