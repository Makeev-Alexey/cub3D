/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:40:21 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:28:41 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*new;

	counter = 0;
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[counter] != '\0')
	{
		new[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	new[counter] = '\0';
	return (new);
}
