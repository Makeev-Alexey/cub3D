/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:23:40 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/20 07:26:38 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_savecheck(char *arg, char *save)
{
	int	a;

	a = 0;
	while (arg[a] == save[a])
	{
		if (arg[a] == '\0' && save[a] == '\0')
			return (1);
		a++;
	}
	return (0);
}

int	ft_namecheck(char *arg, char *ext)
{
	int	a;

	a = 0;
	while (arg[a] != '\0')
		a++;
	if ((a > 4 && arg[a - 1] == ext[2] && arg[a - 2] == ext[1])
			&& (arg[a - 3] == ext[0] && arg[a - 4] == '.'))
		return (1);
	return (0);
}

int	ft_mapcheck(t_all *s)
{
	int	x;
	int	y;
	int tmp;

	x = 0;
	y = 0;
	while (x < s->map.y)
	{
		y = 0;
		while (y < s->map.x)
		{
			tmp = ft_iscorrect2(s->map.tab[x][y]);
			if (tmp != 1 && x == 0)
				return (-1);
			else if (tmp != 1 && x == s->map.y - 1)
				return (-1);
			else if (tmp != 1 && y == 0)
				return (-1);
			else if (tmp != 1 && y == s->map.x - 1)
				return (-1);
			y++;
		}
		x++;
	}
	return (ft_mapcheck2(s));
}

int	ft_parcheck(t_all *s)
{
	if (s->win.x <= 0 || s->win.y <= 0)
		return (ft_strerror(-14));
	else if ((s->tex.n == NULL || s->tex.s == NULL || s->tex.e == NULL)
			|| (s->tex.w == NULL || s->tex.i == NULL))
		return (ft_strerror(-15));
	else if (s->tex.c == 0xFF000000 || s->tex.f == 0xFF000000)
		return (ft_strerror(-16));
	else if (s->err.p == 0)
		return (ft_strerror(-17));
	else if (s->err.p > 1)
		return (ft_strerror(-18));
	else if (ft_mapcheck(s) == -1)
		return (ft_strerror(-19));
	return (1);
}

int	ft_mapcheck2(t_all *s)
{
	int x;
	int y;
	int tmp;

	x = 0;
	y = 0;
	while (x < s->map.y)
	{
		y = 1;
		while (y < s->map.x)
		{
			tmp = is_correct(s->map.tab[x][y]);
			if (tmp != 0 && s->map.tab[x + 1][y] == ' ')
				return (-1);
			else if (tmp != 0 && s->map.tab[x - 1][y] == ' ')
				return (-1);
			else if (tmp != 0 && s->map.tab[x][y + 1] == ' ')
				return (-1);
			else if (tmp != 0 && s->map.tab[x][y - 1] == ' ')
				return (-1);
			y++;
		}
		x++;
	}
	return (map_check_3(s));
}
