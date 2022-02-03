/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:44:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 17:58:06 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * esc) and q(12) - exit
 * M(46) and J(38) - mandelbrot and julia sets
 * arrows left(123), right(124), down(125), top(126)
 */

int	deal_key(int key, t_info *fr)
{
	if (key <= 60)
	{
		if (key == 53 || key == 12)
		{
			free (fr);
			exit(0);
		}
		else if (key == 46)
			init_mandelbrot(fr);
		else if (key == 38)
			init_julia(fr);
		else if (key == 17)
		{
			fr->Maxint = 1;
			init_tree(fr);
		}
		plot_window(fr);
	}
	else
		deal_key2(key, fr);
	return (0);
}

int	deal_key2(int key, t_info *fr)
{
	if (key == 123)
		panning_x(fr, -0.05);
	else if (key == 124)
		panning_x(fr, 0.05);
	else if (key == 125)
		panning_y(fr, -0.05);
	else if (key == 126)
		panning_y(fr, 0.05);
	else if (key == 69 && fr->name_fr == 't')
	{
		fr->Maxint++;
		init_tree(fr);
	}
	else if (key == 78 && fr->name_fr == 't')
	{
		fr->Maxint--;
		init_tree(fr);
	}
	plot_window(fr);
	return (0);
}

void	panning_x(t_info *fr, double p)
{
	double	re;

	re = fr->rmax - fr->rmin;
	fr->rmin = fr->rmin + re * p;
	fr->rmax = fr->rmax + re * p;
}

void	panning_y(t_info *fr, double p)
{
	double	im;

	im = fr->imax - fr->imin;
	fr->imin = fr->imin + im * p;
	fr->imax = fr->imax + im * p;
}
