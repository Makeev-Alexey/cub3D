/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsacha <dsacha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 07:52:34 by dsacha            #+#    #+#             */
/*   Updated: 2020/11/22 22:15:50 by dsacha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>
# include <math.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPEED 15
# define TURN 0.05
# define IMG_PTR s->ptex[s->count]

typedef struct	s_mlx
{
	void *ptr;
}				t_mlx;

typedef struct	s_win
{
	void	*ptr;
	int		x;
	int		y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				fsh;
}				t_img;

typedef struct	s_err
{
	int	n;
	int	m;
	int	p;
}				t_err;

typedef struct	s_map
{
	char	**tab;
	int		x;
	int		y;
	int		spr;
}				t_map;

typedef struct	s_tex
{
	unsigned int *n;
	unsigned int *s;
	unsigned int *e;
	unsigned int *w;
	unsigned int *i;
	unsigned int c;
	unsigned int f;
}				t_tex;

typedef struct	s_pos
{
	double x;
	double y;
}				t_pos;

typedef struct	s_dir
{
	double	x;
	double	y;
	double	a;
}				t_dir;

typedef struct	s_ray
{
	double	x;
	double	y;
	int		i;
	double	v;
	double	w;
}				t_ray;

typedef struct	s_hit
{
	double	x;
	double	y;
	double	d;
}				t_hit;

typedef struct	s_spr
{
	double	x;
	double	y;
	double	d;
}				t_spr;

typedef struct	s_stk
{
	double	x;
	double	y;
	double	d;
}				t_stk;

typedef struct	s_all
{
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;
	t_map	map;
	t_tex	tex;
	t_pos	pos;
	t_dir	dir;
	t_ray	ray;
	t_hit	hit;
	t_spr	*spr;
	t_stk	*stk;
	void	**ptex;
	int		count;
}				t_all;

int				ft_parser(t_all *s, char *cub);
char			*tab(t_all *s, char *line, int *i);
int				tablen(t_all *s, char *line);
int				ft_map(t_all *s, char *line, int *i);
void			ft_init(char *cub, int bmp);
void			ft_init_2(t_all s, char *cub, int bmp);
void			ft_bdraw(t_all *s);
void			ft_draw(t_all *s);
void			ft_sdraw(t_all *s, int loc, double dist);
void			ft_sprite_draw(t_all *s);
int				ft_cubed(t_all s, char *cub, int bmp);
void			ft_move(t_all *s, double c);
void			ft_strafe(t_all *s, double c);
void			ft_turn(t_all *s, double c);
int				ft_key(int key, void *arg);
unsigned int	ft_spixel(t_all *s, int index, unsigned int col);
void			ft_ray(t_all *s);
void			ft_dir(t_all *s);
void			ft_ver(t_all *s);
void			ft_pos(t_all *s);
void			ft_screen(t_all *s);
unsigned int	ft_pixel(t_all *s, double i);
void			ft_column(t_all *s, int size);
int				ft_size(t_all *s);
void			ft_stock(t_all *s);
int				ft_texture(t_all *s, unsigned int **adr, char *line, int *i);
int				ft_res(t_all *s, char *line, int *i);
int				ft_get_colors(unsigned int *color, char *line, int *i);
int				ft_atoi_mod(char *line, int *i);
void			ft_sorder(t_all *s);
void			ft_slocate(t_all *s, double dirx, double diry, double dist);
void			ft_bfile(t_all *s, int fd);
void			ft_binfo(t_all *s, int fd);
void			ft_bdata(t_all *s, int fd);
int				ft_bitmap(t_all *s);
int				ft_close(t_all *s, int win);
void			ft_hor(t_all *s);
int				ft_slist(t_all *s);
int				ft_xpm(t_all *s, unsigned int **adr, char *file);
int				get_next_line(int fd, char **line);
int				ft_line(t_all *s, char *line);
int				ft_mapcheck2(t_all *s);
int				is_correct(char a);
int				ft_savecheck(char *arg, char *save);
int				ft_namecheck(char *arg, char *ext);
int				ft_mapcheck(t_all *s);
int				ft_parcheck(t_all *s);
int				ft_strerror(int err_num);
int				ft_spaceskip(char *line, int *i);
int				newline_check(char *stock, int read_size);
char			*buf_join(char *stock, char *buf);
char			*stock_trim(char *stock);
char			*get_line(char *stock);
char			*error(char *stock);
int				ft_iscorrect2(char c);
int				map_trim2(t_all *s);
int				map_check_3(t_all *s);
void			ft_map_rework(t_all *s);

#endif
