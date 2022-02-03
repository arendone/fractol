/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:56:40 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 18:01:52 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdarg.h>

# define WHEEL_DOWN 4
# define WHEEL_UP 5

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		rmin;
	double		rmax;
	double		imin;
	double		imax;
	double		Z_re;
	double		Z_im;
	double		Z_re2;
	double		Z_im2;
	bool		isInside;
	int			Maxint;
	char		name_fr;
	char		color;
	double		K_re;
	double		K_im;
}	t_info;

/* file utils.c */
void	my_mlx_pixel_put(t_info *fr, int x, int y, int color);
void	init_window(t_info *fr);
void	plot_window_firsttime(t_info *fr);
void	plot_window(t_info *fr);
int		print_error(void);

/* file inter_key.c */
int		deal_key(int key, t_info *fr);
int		deal_key2(int key, t_info *fr);
void	panning_x(t_info *fr, double p);
void	panning_y(t_info *fr, double p);

/* file inter_mouse.c */
int		mouse_hook(int	mousecode, int x, int y, t_info *fr);
void	set_zoom(int mousecode, int *x, int *y, t_info *fr);
int		clean_destroy(t_info *fr);

/* colors.c */
int		add_shade(int color, float transp);
int		color_fuego(int n);
int		color_psycho(int n);
int		color_lila(int n);
void	paint_imagen_black(t_info *fr);

/*mandelbrot.c */
void	init_mandelbrot(t_info *fr);
void	mandelbrot(t_info *fr);
void	mandelbrot2(t_info *fr, t_point p, double c_re, double c_im);
void	color_point_mandelbrot(t_info *fr, int x, int y, int n);

/*julia.c */
void	init_julia(t_info *fr);
void	julia(t_info *fr);
void	julia2(t_info *fr, int x, int y);
void	color_point_julia(t_info *fr, int x, int y, int n);

/*tree.c */
void	color_point_tree(t_info *fr, int x, int y, int times);
void	draw_line(t_info *fr, t_point p1, t_point p2, int times);
void	pythagorasTree(t_info *fr, t_point a, t_point b, int times);
void	init_tree(t_info *fr);

/* ft_atof.c */
double	ft_atof(char *str);

/* read arguments in read_arg.c */
int		init_t_info(t_info *fr, int arg, char **str);
int		compare(char *s1, char *s2, size_t n);
int		control_name(char *name, t_info *fr);
int		control_color(char *color, t_info *fr);
int		control_k(char *param, t_info *fr, char t);
#endif