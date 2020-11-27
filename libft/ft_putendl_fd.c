/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:58:37 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:22:25 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		counter;
	char	a;

	counter = 0;
	a = '\n';
	while (s[counter] != '\0')
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	write(fd, &a, 1);
}
