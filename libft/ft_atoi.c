/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 08:20:01 by student           #+#    #+#             */
/*   Updated: 2020/06/02 15:08:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int result;
	int flag;

	flag = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (flag == -1)
		return (result * (-1));
	return (result);
}
