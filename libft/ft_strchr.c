/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 07:23:18 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:25:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	char	*s1;

	counter = 0;
	s1 = (char *)s;
	while (s1[counter] && s1[counter] != '\0' && s1[counter] != c)
		counter++;
	if (s1[counter] == (unsigned char)c)
		return (&s1[counter]);
	return (NULL);
}
