/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 06:00:21 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/17 08:05:37 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*error(char *stock)
{
	free(stock);
	return (NULL);
}

int		ft_cubed(t_all s, char *cub, int bmp)
{
	t_pos	pos;
	t_dir	dir;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	s.pos = pos;
	s.dir = dir;
	s.mlx.ptr = mlx_init();
	if (ft_parser(&s, cub) == -1)
		return (ft_close(&s, 0));
	if (bmp == 1)
		return (ft_bitmap(&s));
	ft_turn(&s, 1);
	ft_move(&s, 1);
	ft_turn(&s, -1);
	ft_move(&s, -1);
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	ft_draw(&s);
	mlx_hook(s.win.ptr, 2, 0, ft_key, &s);
	mlx_hook(s.win.ptr, 17, 0, ft_close, &s);
	mlx_loop(s.mlx.ptr);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
		ft_init(av[1], 1);
	else if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_init(av[1], 0);
	else
		write(2, "Error/n Invalid arguments/n", 27);
	return (0);
}
