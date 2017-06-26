/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:19:09 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/13 15:55:17 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_for_color(t_fdf *res, int j)
{
	int i;

	i = 0;
	while (res->line[j][i] != '\0')
	{
		res->com = 0;
		if (res->line[j][i] == ',')
		{
			res->com = 1;
			return ;
		}
		i++;
	}
}

void	col_height(t_fdf *res, int x, int y, int col)
{
	int i;
	int color;

	i = 0;
	color = col;
	if (res->cord[x][y].h >= 0)
	{
		while (i != res->cord[x][y].h)
		{
			color += 0x60E0E;
			i++;
		}
	}
	if (res->cord[x][y].h <= 0)
	{
		while (i != res->cord[x][y].h)
		{
			color -= 0x60E0E;
			i--;
		}
	}
	res->col2 = color;
}

void	zoom(t_fdf *res)
{
	int x;
	int y;

	y = 0;
	while (y < res->count_y)
	{
		x = 0;
		while (x < res->count_x)
		{
			res->cord[y][x].x *= res->dr.x1;
			res->cord[y][x].y *= res->dr.x1;
			x++;
		}
		y++;
	}
}

void	move(t_fdf *res)
{
	int x;
	int y;

	y = 0;
	while (y < res->count_y)
	{
		x = 0;
		while (x < res->count_x)
		{
			res->cord[y][x].x += RESO_X / 4;
			res->cord[y][x].x += res->x;
			res->cord[y][x].y += (RESO_Y / 4) - 150;
			res->cord[y][x].y += res->y;
			x++;
		}
		y++;
	}
}

void	rotate(t_fdf *res)
{
	int x;
	int y;
	int t_x;
	int t_y;

	y = 0;
	while (y < res->count_y)
	{
		x = 0;
		while (x < res->count_x)
		{
			t_x = res->cord[y][x].x;
			t_y = res->cord[y][x].y;
			res->cord[y][x].x = res->xp + (t_x - res->xp) * cos(res->q)
				+ ((res->cord[y][x].h * res->dr.x2) - res->yp) * sin(res->q);
			res->cord[y][x].y = res->yp + ((res->cord[y][x].h * res->dr.x2)
					- res->yp) * sin(res->z) + (t_y - res->xp) * cos(res->z);
			x++;
		}
		y++;
	}
}
