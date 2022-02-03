/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:37:35 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 17:21:42 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_info *fr)
{
	fr->rmin = -2.0;
	fr->rmax = 1.0;
	fr->imin = -1.2;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);
	fr->name_fr = 'm';
	fr->Maxint = 60;
	mandelbrot(fr);
}

void	mandelbrot(t_info *fr)
{
	t_point	p;
	double	c_re;
	double	c_im;

	p.x = 0;
	while (p.x < (fr->img_width))
	{
		c_re = (fr->rmin) + (p.x * (fr->rmax - fr->rmin) / (fr->img_width - 1));
		p.y = 0;
		while (p.y < (fr->img_height))
		{
			c_im = (fr->imax) - (p.y * (fr->imax - fr->imin)
					/ (fr->img_height - 1));
			fr->Z_re = c_re;
			fr->Z_im = c_im;
			mandelbrot2(fr, p, c_re, c_im);
			p.y++;
		}
		p.x++;
	}
}

void	mandelbrot2(t_info *fr, t_point p, double c_re, double c_im)
{
	int		n;

	fr->isInside = true;
	n = 0;
	while (n <= (fr->Maxint))
	{
		fr->Z_re2 = fr->Z_re * fr->Z_re;
		fr->Z_im2 = fr->Z_im * fr->Z_im;
		if (((fr->Z_re * fr->Z_re) + (fr->Z_im * fr->Z_im)) > 4)
		{
			fr->isInside = false;
			break ;
		}
		fr->Z_im = (2 * fr->Z_re * fr->Z_im) + c_im;
		fr->Z_re = (fr->Z_re2) - (fr->Z_im2) + c_re;
		n++;
	}
	color_point_mandelbrot(fr, p.x, p.y, n);
}

void	color_point_mandelbrot(t_info *fr, int x, int y, int n)
{
	if (fr->color == 'f' && fr->isInside == false)
	{
		my_mlx_pixel_put(fr, x, y, color_fuego(n));
	}
	if (fr->color == 'p' && fr->isInside == false)
	{
		my_mlx_pixel_put(fr, x, y, color_psycho(n));
	}
	if (fr->color == 'l')
	{
		if (fr->isInside == true)
			my_mlx_pixel_put(fr, x, y, 0x00FFFFFF);
		else
			my_mlx_pixel_put(fr, x, y, color_lila(n));
	}
}
