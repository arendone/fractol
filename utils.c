/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:47:08 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 16:52:51 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_info *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length
			+ x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_window(t_info *fr)
{
	fr->mlx = mlx_init();
	fr->img_width = 1024;
	fr->img_height = 768;
	fr->win = mlx_new_window(fr->mlx, fr->img_width,
			fr->img_height, "Fract-ol");
	fr->img = mlx_new_image(fr->mlx, fr->img_width,
			fr->img_height);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	plot_window_firsttime(fr);
}

void	plot_window_firsttime(t_info *fr)
{
	paint_imagen_black(fr);
	mlx_clear_window(fr->mlx, fr->win);
	if (fr->name_fr == 'm')
		init_mandelbrot(fr);
	if (fr->name_fr == 'j')
		init_julia(fr);
	if (fr->name_fr == 't')
	{
		fr->Maxint = 1;
		init_tree(fr);
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void	plot_window(t_info *fr)
{
	paint_imagen_black(fr);
	mlx_clear_window(fr->mlx, fr->win);
	if (fr->name_fr == 'm')
		mandelbrot(fr);
	if (fr->name_fr == 'j')
		julia(fr);
	if (fr->name_fr == 't')
		init_tree(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

int	print_error(void)
{
	printf("\n\033[0;31mWrong input!\
	\n\033[0;37mThe input should be like: './fractol\033[0;32m   name_of_fractal\
	\033[0;33mset_of_colors\033[0;34m   K_re\033[0;35m   K_im\033[0;37m'\
	\n\033[0;32m -Fractals: mandelbrot, julia, tree\
	\n\033[0;33m -Set of colors : fuego, psycho, lila\
	\n\033[0;34m -Value of K_re (Only for fractal Julia)\
	\n\033[0;35m -Value of K_im (Only for fractal Julia)\
	\n\033[0;37m*Only name_of_fractal is essential :)\
	\n\033[0;37m* In mandelbrot and julia you can zoom in 'Z' & zoom out 'X' or move with the arrows :)\
	\n\033[0;37m* The tree is interactive with '+' && '-'  :)\n\n");
	return (EXIT_FAILURE);
}
