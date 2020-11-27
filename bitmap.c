/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:24:47 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 21:39:16 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bdata(t_all *s, int fd)
{
	int				a;
	int				b;
	unsigned char	buffer[4];

	a = s->win.x * (s->win.y - 1);
	while (a >= 0)
	{
		b = 0;
		while (b < s->win.x)
		{
			buffer[0] = (unsigned char)(s->img.adr[a] % 256);
			buffer[1] = (unsigned char)(s->img.adr[a] / 256 % 256);
			buffer[2] = (unsigned char)(s->img.adr[a] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			a++;
			b++;
		}
		a -= 2 * s->win.x;
	}
}

void	ft_binfo(t_all *s, int fd)
{
	int				runner;
	unsigned char	header[40];

	runner = 0;
	while (runner < 40)
		header[runner++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	runner = s->win.x;
	header[4] = (unsigned char)(runner % 256);
	header[5] = (unsigned char)(runner / 256 % 256);
	header[6] = (unsigned char)(runner / 256 / 256 % 256);
	header[7] = (unsigned char)(runner / 256 / 256 / 256);
	runner = s->win.y;
	header[8] = (unsigned char)(runner % 256);
	header[9] = (unsigned char)(runner / 256 % 256);
	header[10] = (unsigned char)(runner / 256 / 256 % 256);
	header[11] = (unsigned char)(runner / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_all *s, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = s->win.x * s->win.y * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int		ft_bitmap(t_all *s)
{
	int	fd;

	ft_bdraw(s);
	fd = open("cub3d.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(s, fd);
	ft_binfo(s, fd);
	ft_bdata(s, fd);
	close(fd);
	free(s->img.ptr);
	free(s->img.adr);
	ft_close(s, 0);
	return (1);
}

int		ft_close(t_all *s, int win)
{
	int	a;

	a = 0;
	while (a < s->map.y)
		free(s->map.tab[a++]);
	free(s->map.tab);
	if (win == 1)
		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
	a = 0;
	while (a < s->count)
		mlx_destroy_image(s->mlx.ptr, s->ptex[a++]);
	free(s->ptex);
	free(s->mlx.ptr);
	exit(0);
	return (1);
}
