/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 08:11:04 by student           #+#    #+#             */
/*   Updated: 2020/06/04 00:41:45 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			res;

	res = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while (tmp1[res] == tmp2[res] && tmp1[res] != '\0' && res < len - 1)
		res++;
	return (tmp1[res] - tmp2[res]);
}
