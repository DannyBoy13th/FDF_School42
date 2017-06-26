/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:27:33 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/19 18:11:24 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	operations(t_fdf *res)
{
	mlx_destroy_image(res->mlx, res->img);
	res->img = mlx_new_image(res->mlx, RESO_X, RESO_Y);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->sl, &res->end);
	erase(res);
	zoom(res);
	move(res);
	rotate(res);
}

void	mlx_launcher(t_fdf *res)
{
	res->dr.x1 = RESO_X / (res->count_x * 2);
	res->dr.x2 = 1.0;
	res->x = 1;
	res->y = 1;
	res->z = 6.0;
	res->q = 0.1;
	res->xp = 500 + res->x;
	res->yp = 500 + res->y;
	res->mlx = mlx_init();
	res->win = mlx_new_window(res->mlx, RESO_X, RESO_Y, "fdf");
	res->img = mlx_new_image(res->mlx, RESO_X, RESO_Y);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->sl, &res->end);
	mlx_hook(res->win, 2, 3, hook_operators, res);
	res->col = 0xD13030;
	draw_image(res, res->col);
}

int		main(int argc, char **argv)
{
	int				r;
	static	t_fdf	res;

	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments!\n");
		return (0);
	}
	if (res.file == NULL)
		res.file = ft_strnew(1);
	res.fd = open(argv[1], O_RDONLY);
	if (read_line(res.fd, &res.file) < 0)
	{
		ft_putstr("No such file.\n");
		return (0);
	}
	while (read_line(res.fd, &res.file) > 0)
		r = read_line(res.fd, &res.file);
	count_rows(res.file, &res);
	count_ints(res.file, &res);
	parse_ints(&res);
	mlx_launcher(&res);
	mlx_loop(res.mlx);
	return (0);
}
