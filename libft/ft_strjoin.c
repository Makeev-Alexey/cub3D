/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:51:09 by student           #+#    #+#             */
/*   Updated: 2020/06/03 17:30:54 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counter1;
	int		counter2;
	char	*new;

	counter2 = 0;
	counter1 = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(counter1 + 1);
	if (!(new))
		return (NULL);
	new[counter1] = '\0';
	counter1 = 0;
	while (s1[counter1] != '\0')
	{
		new[counter1] = s1[counter1];
		counter1++;
	}
	while (s2[counter2] != '\0')
	{
		new[counter1] = s2[counter2];
		counter1++;
		counter2++;
	}
	return (new);
}
