/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 07:54:54 by student           #+#    #+#             */
/*   Updated: 2020/06/03 10:04:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t lenght;

	if (*need == '\0')
		return ((char *)hay);
	lenght = ft_strlen(need);
	while (*hay != '\0' && len-- >= lenght)
	{
		if (*hay == *need && ft_memcmp(hay, need, lenght) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
