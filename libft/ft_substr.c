/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:35:09 by student           #+#    #+#             */
/*   Updated: 2020/06/02 16:58:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counter;
	char	*new;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	counter = ft_strlen(s + start);
	if (counter < len)
		len = counter;
	(new) = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	counter = 0;
	while (counter < len && s[(size_t)start + counter] != '\0')
	{
		new[counter] = s[(size_t)start + counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}
