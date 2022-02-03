/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:28:56 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 17:36:52 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	add_shade(int color, float transp)
{
	int	entero;
	int	shade;

	entero = 256 * transp;
	shade = entero << 24;
	color = color + shade;
	return (color);
}

/*color fuego - standar */
int	color_fuego(int n)
{
	if (n < 4)
		return (add_shade(0x00900C3F, (n * 0.10)));
	else if (n < 8)
		return (add_shade(0x00C70039, ((n / 2) * 0.10)));
	else if (n < 12)
		return (add_shade(0x00FF5733, ((n / 3) * 0.10)));
	else if (n < 16)
		return (add_shade(0x00FFC30F, ((n / 4) * 0.05)));
	else if (n < 20)
		return (add_shade(0x00900C3F, ((n / 5) * 0.05)));
	else if (n < 24)
		return (add_shade(0x00C70039, ((n / 6) * 0.05)));
	else if (n < 28)
		return (add_shade(0x00FF5733, ((n / 7) * 0.05)));
	else if (n < 32)
		return (add_shade(0x00FFC30F, ((n / 8) * 0.005)));
	else if (n < 40)
		return (add_shade(0x00900C3F, ((n / 9) * 0.005)));
	else if (n < 48)
		return (add_shade(0x00C70039, ((n / 10) * 0.005)));
	else if (n < 56)
		return (add_shade(0x00FF5733, ((n / 11) * 0.005)));
	else
		return (0x00000000);
}

/* if I don't use transparency
int	color_fuego(int n)
{
	if (n < 4)
		return (0x00900C3F);
	else if (n < 8)
		return (0x00C70039);
	else if (n < 12)
		return (0x00FF5733);
	else if (n < 16)
		return (0x00FFC30F);
	else if (n < 20)
		return (0x00900C3F);
	else if (n < 24)
		return (0x00C70039);
	else if (n < 28)
		return (0x00FF5733);
	else if (n < 32)
		return (0x00FFC30F);
	else
		return (0x00000000);
} */

/*rosa y verde psicodelico*/
int	color_psycho(int n)
{
	if (n < 4)
		return (add_shade(0x00DF00FF, (n * 0.10)));
	else if (n < 8)
		return (add_shade(0x0021FF00, ((n / 2) * 0.10)));
	else if (n < 12)
		return (add_shade(0x00DF00FF, ((n / 3) * 0.05)));
	else if (n < 16)
		return (add_shade(0x008231FF, ((n / 4) * 0.05)));
	else if (n < 20)
		return (add_shade(0x0031FF82, ((n / 5) * 0.10)));
	else if (n < 24)
		return (add_shade(0x0021FF00, ((n / 6) * 0.10)));
	else if (n < 28)
		return (add_shade(0x00DF00FF, ((n / 7) * 0.05)));
	else if (n < 32)
		return (add_shade(0x008231FF, ((n / 8) * 0.05)));
	else if (n < 40)
		return (add_shade(0x0031FF82, ((n / 9) * 0.005)));
	else if (n < 48)
		return (add_shade(0x0021FF00, ((n / 10) * 0.005)));
	else if (n < 56)
		return (add_shade(0x00DF00FF, ((n / 11) * 0.005)));
	else
		return (0x00000000);
}

/*tonos lila-morado-centro blanco*/
int	color_lila(int n)
{
	if (n < 4)
		return (add_shade(0x009400D3, (n * 0.25)));
	else if (n < 8)
		return (add_shade(0x009400D3, ((n / 2) * 0.25)));
	else if (n < 12)
		return (add_shade(0x005000D3, ((n / 3) * 0.25)));
	else if (n < 16)
		return (add_shade(0x005000D3, ((n / 4) * 0.25)));
	else if (n < 20)
		return (add_shade(0x002500D3, ((n / 5) * 0.25)));
	else if (n < 24)
		return (add_shade(0x002500D3, ((n / 6) * 0.25)));
	else if (n < 28)
		return (add_shade(0x00009999, ((n / 7) * 0.25)));
	else if (n < 32)
		return (add_shade(0x00000000, ((n / 8) * 0.25)));
	else if (n < 40)
		return (add_shade(0x009400D3, ((n / 9) * 0.005)));
	else if (n < 48)
		return (add_shade(0x005000D3, ((n / 10) * 0.005)));
	else if (n < 56)
		return (add_shade(0x002500D3, ((n / 11) * 0.005)));
	else
		return (0x00000000);
}

void	paint_imagen_black(t_info *fr)
{
	int	i;
	int	j;

	i = 0;
	while (i < fr->img_width)
	{
		j = 0;
		while (j < fr->img_height)
		{
			my_mlx_pixel_put(fr, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

/*int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}*/
