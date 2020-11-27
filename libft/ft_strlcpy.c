/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 02:44:11 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:27:46 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t counter;

	counter = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (!dst)
		return (0);
	while (counter < (size - 1) && src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (ft_strlen(src));
}
