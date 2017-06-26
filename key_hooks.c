/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:06:11 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/13 16:12:41 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_move(int key, t_fdf *res)
{
	if (key == 125)
		res->y += 20;
	if (key == 126)
		res->y -= 20;
	if (key == 123)
		res->x -= 20;
	if (key == 124)
		res->x += 20;
}

void	hook_rotate(int key, t_fdf *res)
{
	if (key == 13)
		res->z -= 0.3;
	if (key == 1)
		res->z += 0.3;
	if (key == 0)
		res->q -= 0.3;
	if (key == 2)
		res->q += 0.3;
}

int		hook_operators(int key, t_fdf *res)
{
	if (key == 53)
		exit(0);
	if (key == 14)
		res->dr.x1 = res->dr.x1 * 1.2;
	if (key == 12)
		res->dr.x1 = res->dr.x1 * 0.8;
	if (key == 48)
		res->col += 1000;
	if (key >= 123 && key <= 126)
		hook_move(key, res);
	if (key == 1 || key == 2 || key == 0 || key == 13)
		hook_rotate(key, res);
	if (key == 24)
		res->dr.x2 += 0.2;
	if (key == 27)
		res->dr.x2 -= 0.2;
	draw_image(res, res->col);
	return (0);
}

void	algo_helper_x(t_fdf *res, int x, int y)
{
	res->algo.rx1 = res->cord[y][x].y;
	res->algo.rx2 = res->cord[y][x + 1].y;
	res->algo.ry1 = res->cord[y][x].x;
	res->algo.ry2 = res->cord[y][x + 1].x;
	algo_draw(res);
}

void	algo_helper_y(t_fdf *res, int x, int y)
{
	res->algo.rx1 = res->cord[y][x].y;
	res->algo.rx2 = res->cord[y + 1][x].y;
	res->algo.ry1 = res->cord[y][x].x;
	res->algo.ry2 = res->cord[y + 1][x].x;
	algo_draw(res);
}
