/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:58:43 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/13 12:49:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray(t_all *s)
{
	double angle;
	double dist;

	angle = ((double)s->ray.i - (s->win.x / 2)) * 33 / (s->win.x / 2);
	angle = angle * M_PI / 180;
	s->ray.x = s->dir.x * cos(angle) - s->dir.y * sin(angle);
	s->ray.y = s->dir.y * cos(angle) + s->dir.x * sin(angle);
	dist = hypot(s->ray.x, s->ray.y);
	s->ray.x /= dist;
	s->ray.y /= dist;
}

void	ft_dir(t_all *s)
{
	if (s->ray.x >= 0)
		s->ray.v = 1;
	else
		s->ray.v = 0;
	if (s->ray.y >= 0)
		s->ray.w = 1;
	else
		s->ray.w = 0;
}

void	ft_ver(t_all *s)
{
	double x;
	double y;

	x = floor(s->pos.x) + s->ray.v;
	y = s->pos.y + (x - s->pos.x) * (s->ray.y / s->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < s->map.y)
	{
		if (s->map.tab[(int)floor(y)][(int)(x - 1 + s->ray.v)] == '1')
		{
			s->hit.x = x;
			s->hit.y = y;
			s->hit.d = hypot(x - s->pos.x, y - s->pos.y);
			return ;
		}
		x += (2 * s->ray.v - 1);
		y += (2 * s->ray.v - 1) * s->ray.y / s->ray.x;
	}
	s->hit.x = s->pos.x;
	s->hit.y = s->pos.y;
	s->hit.d = 1000000000;
}
