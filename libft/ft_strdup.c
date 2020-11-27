/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:19:49 by student           #+#    #+#             */
/*   Updated: 2020/06/05 06:30:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		lenght;

	lenght = ft_strlen(s1);
	new = (char *)malloc(lenght + 1);
	if (!(new))
		return (NULL);
	new[lenght] = '\0';
	while (lenght >= 0)
	{
		new[lenght] = s1[lenght];
		lenght--;
	}
	return (new);
}
