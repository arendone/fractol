/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:42:24 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 18:02:10 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int	mousecode, int x, int y, t_info *fr)
{
	if (mousecode == WHEEL_UP || mousecode == WHEEL_DOWN)
		set_zoom(mousecode, &x, &y, fr);
	return (0);
}

void	set_zoom(int mousecode, int *x, int *y, t_info *fr)
{
	double	zoom;
	double	r_pos;
	double	i_pos;

	if (mousecode == WHEEL_DOWN)
		zoom = 0.833;
	if (mousecode == WHEEL_UP)
		zoom = 1.2;
	r_pos = fr->rmin + (double) *x / (fr->img_width - 1)
		* (fr->rmax - fr->rmin);
	i_pos = fr->imax - (double) *y / (fr->img_height - 1)
		* (fr->imax - fr->imin);
	fr->rmax = r_pos
		+ (fr->rmax - r_pos) * zoom;
	fr->rmin = r_pos
		+ (fr->rmin - r_pos) * zoom;
	fr->imax = i_pos
		+ (fr->imax - i_pos) * zoom;
	fr->imin = i_pos
		+ (fr->imin - i_pos) * zoom;
	plot_window(fr);
}

int	clean_destroy(t_info *fr)
{
	free(fr);
	exit (0);
	return (0);
}
