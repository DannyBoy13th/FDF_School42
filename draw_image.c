/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:22:55 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/13 16:20:39 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pix(int y, int x, int color, t_fdf *res)
{
	if (y >= RESO_Y || x >= RESO_X || y <= 0 || x <= 0)
		return ;
	res->addr[y * res->sl + x * 4] = color & 0x0000ff;
	res->addr[y * res->sl + x * 4 + 1] = (color >> 8) & 0xff;
	res->addr[y * res->sl + x * 4 + 2] = (color >> 16);
}

void	algo_draw(t_fdf *res)
{
	res->algo.x1 = abs(res->algo.rx2 - res->algo.rx1);
	res->algo.x2 = res->algo.rx1 < res->algo.rx2 ? 1 : -1;
	res->algo.y1 = -abs(res->algo.ry2 - res->algo.ry1);
	res->algo.y2 = res->algo.ry1 < res->algo.ry2 ? 1 : -1;
	res->algo.i = res->algo.x1 + res->algo.y1;
	while (1)
	{
		ft_put_pix(res->algo.rx1, res->algo.ry1, res->col2, res);
		if (res->algo.rx1 == res->algo.rx2 && res->algo.ry1 == res->algo.ry2)
			break ;
		res->algo.j = 2 * res->algo.i;
		if (res->algo.j > res->algo.y1)
		{
			res->algo.i += res->algo.y1;
			res->algo.rx1 += res->algo.x2;
		}
		if (res->algo.j < res->algo.x1)
		{
			res->algo.i += res->algo.x1;
			res->algo.ry1 += res->algo.y2;
		}
	}
}

void	draw_image(t_fdf *res, int col)
{
	int x;
	int y;

	operations(res);
	y = 0;
	while (y < res->count_y)
	{
		x = 0;
		while (x < res->count_x)
		{
			col_height(res, y, x, col);
			if (x + 1 < res->count_x)
				algo_helper_x(res, x, y);
			if (y + 1 < res->count_y)
				algo_helper_y(res, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(res->mlx, res->win, res->img, 0, 0);
}

void	erase(t_fdf *res)
{
	int x;
	int y;

	y = 0;
	while (y < res->count_y)
	{
		x = 0;
		while (x < res->count_x)
		{
			res->cord[y][x].x = x;
			res->cord[y][x].y = y;
			x++;
		}
		y++;
	}
}
