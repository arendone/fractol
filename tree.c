/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:06:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/02 15:58:56 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_point_tree(t_info *fr, int x, int y, int times)
{
	if (fr->color == 'f')
	{
		my_mlx_pixel_put(fr, x, y, color_fuego(times));
	}
	if (fr->color == 'p')
	{
		my_mlx_pixel_put(fr, x, y, color_psycho(times));
	}
	if (fr->color == 'l')
	{
		my_mlx_pixel_put(fr, x, y, color_lila(times));
	}
}

//void	line(t_info *fr, int p1.x, int p1.y, int p2.x, int by, int color)
void	draw_line(t_info *fr, t_point p1, t_point p2, int times)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	double	pixelX;
	double	pixelY;

	deltaX = p2.x - p1.x;
	deltaY = p2.y - p1.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = p1.x;
	pixelY = p1.y;
	while (pixels)
	{
		color_point_tree(fr, pixelX, pixelY, times * 2);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
}

void	pythagorasTree(t_info *fr, t_point a, t_point b, int times)
{
	t_point	c;
	t_point	d;
	t_point	e;

	c.x = b.x - (a.y - b.y);
	c.y = b.y - (b.x - a.x);
	d.x = a.x - (a.y - b.y);
	d.y = a.y - (b.x - a.x);
	e.x = d.x + (b.x - a.x - (a.y - b.y)) / 2;
	e.y = d.y - (b.x - a.x + a.y - b.y) / 2;
	if (times > 0)
	{
		draw_line(fr, a, b, times);
		draw_line(fr, c, b, times);
		draw_line(fr, c, d, times);
		draw_line(fr, a, d, times);
		pythagorasTree(fr, d, e, times - 1);
		pythagorasTree(fr, e, c, times - 1);
	}
}

void	init_tree(t_info *fr)
{
	t_point	a;
	t_point	b;

	a.x = (fr->img_width / 2) - 76;
	a.y = (fr->img_height) - 64;
	b.x = (fr->img_width / 2) + 76;
	b.y = (fr->img_height) - 64;
	fr->name_fr = 't';
	pythagorasTree(fr, a, b, fr->Maxint);
}
