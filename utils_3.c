/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:17:38 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 23:29:59 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi_mod(char *line, int *i)
{
	int	num;
	int check;

	num = 0;
	check = 0;
	ft_spaceskip(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
		check++;
	}
	if (check == 0)
		return (-1);
	return (num);
}

void	ft_slocate(t_all *s, double dirx, double diry, double dist)
{
	double ang;

	dirx = (dirx - s->pos.x) / dist;
	diry = (diry - s->pos.y) / dist;
	if (diry <= 0)
		ang = acos(dirx) * 180 / M_PI;
	else
		ang = 360 - acos(dirx) * 180 / M_PI;
	ang = s->dir.a - ang + 33;
	if (ang >= 180)
		ang -= 360;
	else if (ang <= -180)
		ang += 360;
	ft_sdraw(s, ang * s->win.x / 66, dist);
}

void	ft_sorder(t_all *s)
{
	t_spr	tmp;
	int		a;
	int		b;

	a = 0;
	while (a < s->map.spr - 1)
	{
		b = a + 1;
		while (b < s->map.spr)
		{
			if (s->spr[a].d < s->spr[b].d)
			{
				tmp = s->spr[a];
				s->spr[a] = s->spr[b];
				s->spr[b] = tmp;
			}
			b++;
		}
		a++;
	}
}

int		ft_iscorrect2(char c)
{
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

int		map_trim2(t_all *s)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < s->map.y)
	{
		y = 1;
		while (y < s->map.x)
		{
			if (s->map.tab[x][y] == ' ')
				s->map.tab[x][y] = '1';
			y++;
		}
		x++;
	}
	return (1);
}
