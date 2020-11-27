/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 06:50:02 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/15 04:44:28 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strerror(int err_num)
{
	(err_num == -1) ? write(2, "Error\n Couldn't open file (FD)\n", 31) : 0;
	(err_num == -2) ? write(2, "Error\n Couldn't parse file (GNL)\n", 34) : 0;
	(err_num == -3) ? write(2, "Error\n Resolution specified twice\n", 35) : 0;
	(err_num == -4) ? write(2, "Error\n Invalid resolution\n", 27) : 0;
	(err_num == -5) ? write(2, "Error\n Floor/ceiling specified 2", 38) : 0;
	(err_num == -6) ? write(2, "Error\n Invalid floor/ceiling line\n", 35) : 0;
	(err_num == -7) ? write(2, "Error\n Texture specified twice\n", 32) : 0;
	(err_num == -8) ? write(2, "Error\n Malloc fail (texture path)\n", 35) : 0;
	(err_num == -9) ? write(2, "Error\n Invalid texture image\n", 30) : 0;
	(err_num == -10) ? write(2, "Error\n Invalid line in file\n", 29) : 0;
	(err_num == -11) ? write(2, "Error\n Malloc fail (map table)\n", 32) : 0;
	(err_num == -12) ? write(2, "Error\n Invalid map\n", 20) : 0;
	(err_num == -14) ? write(2, "Error\n No resolution specified\n", 32) : 0;
	(err_num == -15) ? write(2, "Error\n Missing texture\n", 24) : 0;
	(err_num == -16) ? write(2, "Error\n No floor/ceiling color\n", 31) : 0;
	(err_num == -17) ? write(2, "Error\n No player\n", 18) : 0;
	(err_num == -18) ? write(2, "Error\n too many players\n", 25) : 0;
	(err_num == -19) ? write(2, "Error\n Open map\n", 17) : 0;
	return (-1);
}
