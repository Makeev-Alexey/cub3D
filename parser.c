/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 07:14:13 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 23:24:12 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parser(t_all *s, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(-1));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_line(s, line) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (ret == -1 || ret == -3)
		return (ft_strerror(ret + 1));
	ft_map_rework(s);
	ft_pos(s);
	s->spr = NULL;
	ft_slist(s);
	return (ft_parcheck(s));
}

void	ft_pos(t_all *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->map.y)
	{
		while (++j < s->map.x)
		{
			c = s->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				s->pos.y = (double)i + 0.5;
				s->pos.x = (double)j + 0.5;
				s->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				s->dir.x *= (c == 'W') ? -1 : 1;
				s->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				s->dir.y *= (c == 'N') ? -1 : 1;
				s->err.p++;
			}
		}
		j = -1;
	}
}

int		ft_texture(t_all *s, unsigned int **adr, char *line, int *i)
{
	char	*file;
	int		j;

	if (*adr != NULL)
		return (-7);
	(*i) += 2;
	ft_spaceskip(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
		return (-8);
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		file[j++] = line[(*i)++];
	file[j] = '\0';
	j = ft_xpm(s, adr, file);
	free(file);
	return (j == -1 ? -9 : 0);
}

int		ft_res(t_all *s, char *line, int *i)
{
	if (s->win.x != 0 || s->win.y != 0)
		return (-3);
	(*i)++;
	s->win.x = ft_atoi_mod(line, i);
	s->win.y = ft_atoi_mod(line, i);
	if (s->win.x > 1792)
		s->win.x = 1792;
	if (s->win.y > 1120)
		s->win.y = 1120;
	ft_spaceskip(line, i);
	if (s->win.x <= 0 || s->win.y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}

int		ft_get_colors(unsigned int *color, char *line, int *i)
{
	int r;
	int g;
	int b;

	if (*color != 0xFF000000)
		return (-5);
	(*i)++;
	r = ft_atoi_mod(line, i);
	(*i)++;
	g = ft_atoi_mod(line, i);
	(*i)++;
	b = ft_atoi_mod(line, i);
	ft_spaceskip(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255
	|| r < 0 || g < 0 || b < 0)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}
