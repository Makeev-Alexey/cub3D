/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:42:32 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/13 18:49:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_bdraw(t_all *s)
{
	t_ray ray;
	t_hit hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	s->ray = ray;
	s->hit = hit;
	ft_screen(s);
}

void			ft_draw(t_all *s)
{
	t_ray ray;
	t_hit hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	s->ray = ray;
	s->hit = hit;
	ft_screen(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	mlx_destroy_image(s->mlx.ptr, s->img.ptr);
}

void			ft_sdraw(t_all *s, int loc, double dist)
{
	unsigned int	col;
	double			size;
	int				index;
	int				a;
	int				b;

	a = 0;
	b = 0;
	size = s->win.y / dist / 2;
	loc = loc - size / 2;
	while (a < size)
	{
		while ((loc + a >= 0 && loc + a < s->win.x) &&
				(b < size && s->stk[loc + a].d > dist))
		{
			col = 64 * floor(64 * (double)b / size) + (double)a / size * 64;
			col = s->tex.i[col];
			index = loc + a + (s->win.y / 2 + b) * s->win.x;
			if (index < s->win.x * s->win.y)
				s->img.adr[index] = ft_spixel(s, index, col);
			b++;
		}
		a++;
		b = 0;
	}
}

void			ft_sprite_draw(t_all *s)
{
	int		i;
	double	dist;

	dist = hypot(s->dir.x, s->dir.y);
	if (s->dir.y <= 0)
		s->dir.a = acos(s->dir.x / dist) * 180 / M_PI;
	else
		s->dir.a = 360 - acos(s->dir.x / dist) * 180 / M_PI;
	i = 0;
	while (i < s->map.spr)
	{
		s->spr[i].d = hypot(s->spr[i].x - s->pos.x, s->spr[i].y - s->pos.y);
		i++;
	}
	ft_sorder(s);
	i = 0;
	while (i < s->map.spr)
	{
		ft_slocate(s, s->spr[i].x, s->spr[i].y, s->spr[i].d);
		i++;
	}
	free(s->stk);
}

unsigned int	ft_spixel(t_all *s, int index, unsigned int col)
{
	int t;
	int r;
	int g;
	int b;

	if (col >= 0xFF000000)
		return (s->img.adr[index]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256);
	g = (col / 256 % 256) * (1 - (double)t / 256);
	b = (col % 256) * (1 - (double)t / 256);
	r += (s->img.adr[index] / (256 * 256) % 256) * ((double)t / 256);
	g += (s->img.adr[index] / 256 % 256) * ((double)t / 256);
	b += (s->img.adr[index] % 256) * ((double)t / 256);
	return (r * 256 * 256 + g * 256 + b);
}
