/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:22:52 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/13 18:29:59 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# define RESO_X 1920
# define RESO_Y 1080

typedef struct	s_cord
{
	int			x;
	int			y;
	int			h;
	int			color;
}				t_cord;

typedef struct	s_dr
{
	int			a;
	int			b;
	int			c;
	double		x1;
	double		x2;
	int			y;
	int			y2;
}				t_dr;

typedef struct	s_algo
{
	int			x1;
	int			y1;
	double		x2;
	int			y2;
	int			i;
	int			j;
	int			rx1;
	int			rx2;
	int			ry1;
	int			ry2;
}				t_algo;

typedef struct	s_fdf
{
	t_cord		cord[4000][4000];
	t_dr		dr;
	t_algo		algo;
	int			bpp;
	int			sl;
	int			end;
	int			count_x;
	int			count_y;
	char		*file;
	char		**line;
	char		*endl;
	char		*loc;
	char		*map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			**mat;
	int			fd;
	int			pix;
	int			x;
	int			y;
	double		z;
	double		q;
	int			col;
	int			col2;
	int			com;
	int			com2;
	int			xp;
	int			yp;
}				t_fdf;

void			mlx_launcher(t_fdf *res);
void			draw_image(t_fdf *res, int col);
void			ft_put_pix(int y, int x, int color, t_fdf *res);
void			algo_draw(t_fdf *res);
void			algo_helper_x(t_fdf *res, int x, int y);
void			algo_helper_y(t_fdf *res, int x, int y);
void			operations(t_fdf *res);
void			erase(t_fdf *res);
void			check_for_color(t_fdf *res, int j);
void			col_height(t_fdf *res, int x, int y, int col);
void			zoom(t_fdf *res);
void			point_rot(t_fdf *res);
void			move(t_fdf *res);
void			rotate(t_fdf *res);
void			hook_move(int key, t_fdf *res);
void			hook_rotate(int key, t_fdf *res);
int				hook_operators(int key, t_fdf *res);
int				read_line(int fd, char **buf);
void			count_ints(char *str, t_fdf *res);
void			count_rows(char *str, t_fdf *res);
char			*ft_strcombine(char *s1, char *s2);
void			parse_ints(t_fdf *res);

#endif
