/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/03 18:00:08 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*gcc main.c -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o magic */

int	main(int arg, char **str)
{
	t_info	*fr;
	int		ret;

	fr = (t_info *)malloc(sizeof(t_info));
	if (!fr)
		return (-1);
	ret = init_t_info(fr, arg, str);
	if (ret == 0)
	{
		init_window(fr);
		mlx_key_hook(fr->win, deal_key, fr);
		mlx_mouse_hook(fr->win, mouse_hook, fr);
		mlx_hook(fr->win, 17, 0, clean_destroy, fr);
		mlx_loop(fr->mlx);
	}
	else
	{
		free (fr);
		print_error();
		return (-1);
	}
	free (fr);
	return (0);
}
