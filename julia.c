/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:18:29 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 17:32:26 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_info *fr)
{
	fr->rmin = -1.7;
	fr->rmax = 1.7;
	fr->imin = -1.3;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);
	fr->name_fr = 'j';
	fr->Maxint = 60;
	julia(fr);
}

void	julia(t_info *fr)
{
	int		x;
	int		y;
	double	c_re;
	double	c_im;

	x = 0;
	while (x < (fr->img_width))
	{
		c_re = (fr->rmin) + (x * (fr->rmax - fr->rmin) / (fr->img_width - 1));
		y = 0;
		while (y < (fr->img_height))
		{
			c_im = (fr->imax) - (y * (fr->imax - fr->imin)
					/ (fr->img_height - 1));
			fr->Z_re = c_re;
			fr->Z_im = c_im;
			julia2(fr, x, y);
			y++;
		}
		x++;
	}
}

void	julia2(t_info *fr, int x, int y)
{
	int		n;

	fr->isInside = true;
	n = 0;
	while (n <= (fr->Maxint))
	{
		fr->Z_re2 = fr->Z_re * fr->Z_re;
		fr->Z_im2 = fr->Z_im * fr->Z_im;
		if (((fr->Z_re2) + (fr->Z_im2)) > 4)
		{
			fr->isInside = false;
			break ;
		}
		fr->Z_im = (2.0 * fr->Z_re * fr->Z_im) + (fr->K_im);
		fr->Z_re = (fr->Z_re2) - (fr->Z_im2) + (fr->K_re);
		n++;
	}
	color_point_julia(fr, x, y, n);
}

void	color_point_julia(t_info *fr, int x, int y, int n)
{
	if (fr->color == 'f' && fr->isInside == true)
	{
		n = (sqrt(fr->Z_re2 + fr->Z_im2) * 60.0) / 1.0;
		my_mlx_pixel_put(fr, x, y, color_fuego(32 - n));
	}
	if (fr->color == 'p' && fr->isInside == true)
	{
		n = (sqrt(fr->Z_re2 + fr->Z_im2) * 60.0) / 1.0;
		my_mlx_pixel_put(fr, x, y, color_psycho(32 - n));
	}
	if (fr->color == 'l')
	{
		if (fr->isInside == true)
		{
			n = (sqrt(fr->Z_re2 + fr->Z_im2) * 60.0) / 1.0;
			my_mlx_pixel_put(fr, x, y, color_lila(32 - n));
		}
		else
			my_mlx_pixel_put(fr, x, y, 0x00FFFFFF);
	}
}
