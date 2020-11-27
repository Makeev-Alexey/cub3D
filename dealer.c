/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:52:08 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/13 14:25:34 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_all *s, double c)
{
	s->pos.x += c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.x -= c * (s->dir.x * SPEED / 100);
	s->pos.y += c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.y -= c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '2')
	{
		s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] = '0';
		s->map.spr--;
		ft_slist(s);
	}
}

void	ft_strafe(t_all *s, double c)
{
	s->pos.x -= c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.x += c * (s->dir.y * SPEED / 100);
	s->pos.y += c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.y -= c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '2')
	{
		s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] = '0';
		s->map.spr--;
		ft_slist(s);
	}
}

void	ft_turn(t_all *s, double c)
{
	double dist;

	s->dir.x = s->dir.x * cos(c * TURN) - s->dir.y * sin(c * TURN);
	s->dir.y = s->dir.y * cos(c * TURN) + s->dir.x * sin(c * TURN);
	dist = hypot(s->dir.x, s->dir.y);
	s->dir.x /= dist;
	s->dir.y /= dist;
}

int		ft_key(int key, void *arg)
{
	if (key == ESC)
		ft_close(arg, 1);
	else if (key == W)
		ft_move(arg, 1);
	else if (key == A)
		ft_strafe(arg, -1);
	else if (key == S)
		ft_move(arg, -1);
	else if (key == D)
		ft_strafe(arg, 1);
	else if (key == LEFT)
		ft_turn(arg, -1);
	else if (key == RIGHT)
		ft_turn(arg, 1);
	ft_draw(arg);
	return (1);
}
