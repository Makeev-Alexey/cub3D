/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:33:30 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 20:52:44 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_line(t_all *s, char *line)
{
	int i;

	i = 0;
	ft_spaceskip(line, &i);
	if ((line[i] == '1' || s->err.m == 1) && line[i] != '\0')
		s->err.n = ft_map(s, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		s->err.n = ft_res(s, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.e, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		s->err.n = ft_texture(s, &s->tex.i, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		s->err.n = ft_get_colors(&s->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		s->err.n = ft_get_colors(&s->tex.c, line, &i);
	if (ft_spaceskip(line, &i) && s->err.n == 0 && line[i] != '\0')
		return (ft_strerror(-10));
	return (s->err.n < 0 ? ft_strerror(s->err.n) : 0);
}

int		get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[4096];
	static char	*stock = NULL;

	if (line == NULL || fd < 0)
		return (-3);
	*line = NULL;
	read_size = 1;
	while (!(newline_check(stock, read_size)))
	{
		if ((read_size = read(fd, buf, 4095)) == -1)
			return (-3);
		buf[read_size] = '\0';
		if ((stock = buf_join(stock, buf)) == NULL)
			return (-3);
	}
	if ((*line = get_line(stock)) == NULL)
		return (-3);
	if (read_size == 0)
		free(stock);
	if (read_size == 0)
		return (0);
	if ((stock = stock_trim(stock)) == NULL)
		return (-3);
	return (1);
}

int		ft_xpm(t_all *s, unsigned int **adr, char *file)
{
	int		fd;
	int		t[5];

	if (ft_namecheck(file, "xpm") == 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	IMG_PTR = mlx_xpm_file_to_image(s->mlx.ptr, file, &t[0], &t[1]);
	if (IMG_PTR == NULL || t[0] != 64 || t[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(IMG_PTR, &t[2], &t[3], &t[4]);
	++s->count;
	return (0);
}

int		ft_slist(t_all *s)
{
	int i;
	int j;
	int k;

	if (s->spr != NULL)
		free(s->spr);
	if (!(s->spr = malloc(sizeof(t_spr) * s->map.spr)))
		return (-1);
	i = 0;
	j = 0;
	while (j < s->map.y)
	{
		k = 0;
		while (k < s->map.x)
		{
			if (s->map.tab[j][k] == '2')
			{
				s->spr[i].y = (double)j + 0.5;
				s->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}

void	ft_hor(t_all *s)
{
	double y;
	double x;

	y = floor(s->pos.y) + s->ray.w;
	x = s->pos.x + (y - s->pos.y) * (s->ray.x / s->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < s->map.x)
	{
		if (s->map.tab[(int)(y - 1 + s->ray.w)][(int)floor(x)] == '1')
		{
			if (s->hit.d > hypot(x - s->pos.x, y - s->pos.y))
			{
				s->hit.x = x;
				s->hit.y = y;
				s->hit.d = hypot(x - s->pos.x, y - s->pos.y);
			}
			return ;
		}
		y += (2 * s->ray.w - 1);
		x += (2 * s->ray.w - 1) * s->ray.x / s->ray.y;
	}
}
