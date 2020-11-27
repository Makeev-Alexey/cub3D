/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:35:08 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 22:15:50 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map(t_all *s, char *line, int *i)
{
	char	**tmp;
	int		a;

	s->err.m = 1;
	if (!(tmp = malloc(sizeof(char *) * (s->map.y + 2))))
		return (-11);
	a = -1;
	while (++a < s->map.y)
		tmp[a] = s->map.tab[a];
	if ((tmp[s->map.y] = tab(s, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[s->map.y + 1] = NULL;
	if (s->map.y > 0)
		free(s->map.tab);
	s->map.tab = tmp;
	s->map.y++;
	s->map.x = s->map.x < tablen(s, line) ?
	tablen(s, line) : s->map.x;
	return (0);
}

int	is_correct(char a)
{
	if (a == '0' || a == '2' || a == 'N' || a == 'W' || a == 'E' || a == 'S')
		return (1);
	return (0);
}

int	ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int	newline_check(char *stock, int read_size)
{
	int	i;

	i = 0;
	if (stock == NULL)
		return (0);
	if (read_size == 0)
		return (1);
	while (stock[i] != '\0')
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_check_3(t_all *s)
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
			if (tmp != 0 && !(s->map.tab[x + 1][y]))
				return (-1);
			else if (tmp != 0 && !(s->map.tab[x - 1][y]))
				return (-1);
			else if (tmp != 0 && !(s->map.tab[x][y + 1]))
				return (-1);
			else if (tmp != 0 && !(s->map.tab[x][y - 1]))
				return (-1);
			y++;
		}
		x++;
	}
	return (map_trim2(s));
}
