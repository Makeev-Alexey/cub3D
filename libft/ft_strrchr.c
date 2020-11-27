/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 07:49:08 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:37:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*s1;

	counter = 0;
	s1 = (char *)s;
	while (s1[counter])
		counter++;
	while (s1[counter] != (unsigned char)c && counter != 0)
		counter--;
	if (s1[counter] == (unsigned char)c)
		return (&s1[counter]);
	return (NULL);
}
