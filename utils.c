/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:28:33 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 22:15:50 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*tab(t_all *s, char *line, int *i)
{
	char	*tmp;
	int		a;

	if (!(tmp = malloc(sizeof(char) * (tablen(s, line) + 1))))
		return (NULL);
	a = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || ft_iscorrect2(line[*i]) == 1 || line[*i] == 'N')
				|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			tmp[a++] = line[*i];
		else if (line[*i] == '2')
		{
			tmp[a++] = line[*i];
			s->map.spr++;
		}
		else if (line[*i] != ' ')
		{
			free(tmp);
			return (NULL);
		}
		(*i)++;
	}
	tmp[a] = '\0';
	return (tmp);
}

int		tablen(t_all *s, char *line)
{
	int i;
	int run;

	i = 0;
	run = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			run++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			run++;
		else if (line[i] == 'E' || line[i] == ' ')
			run++;
		i++;
	}
	if (s->map.x != 0 && ft_strlen(line) != run)
		return (-1);
	return (run);
}

void	ft_map_rework(t_all *s)
{
	size_t	i[2];
	char	*temp;

	i[0] = 0;
	while (i[0] < s->map.y)
	{
		i[2] = ft_strlen(s->map.tab[i[0]]);
		if (i[2] < s->map.x)
		{
			temp = (char*)malloc(sizeof(char) * (s->map.x + 1));
			i[1] = -1;
			while (++i[1] < i[2])
				temp[i[1]] = s->map.tab[i[0]][i[1]];
			if (!i[0])
				ft_memset(temp + i[2], temp[i[2] - 1], s->map.x - i[2]);
			else
				while (i[2]++ < s->map.x)
					temp[i[2] - 1] = temp[i[2] - 2] == '1' &&
					s->map.tab[i[0] - 1][i[2] - 1] == '1' ? '1' : '0';
			temp[s->map.x] = '\0';
			free(s->map.tab[i[0]]);
			s->map.tab[i[0]] = temp;
		}
		++i[0];
	}
}
