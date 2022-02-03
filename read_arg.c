/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:45 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/01 18:10:39 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*Setting default values for Maxint, color, const K*/
/*Evaluatind and adding the arg info to the t_info */

int	init_t_info(t_info *fr, int arg, char **str)
{
	int	ret;

	fr->Maxint = 30;
	fr->name_fr = 'N';
	fr->color = 'f';
	fr->K_re = .353;
	fr->K_im = .288;
	ret = -1;
	if (arg > 1)
		ret = control_name(&str[1][0], fr);
	if (arg > 2 && ret == 0)
		ret = control_color(&str[2][0], fr);
	else
		fr->color = 'f';
	if (arg > 3)
		ret = control_k(&str[3][0], fr, 'r');
	if (arg > 4)
		ret = control_k(&str[4][0], fr, 'i');
	return (ret);
}

int	compare(char *s1, char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	control_name(char *name, t_info *fr)
{
	size_t	i;
	int		ret;

	ret = -1;
	if (name != NULL)
	{
		i = 0;
		while (name[i] != '\0')
			i++;
		if (i == 10)
			ret = compare(name, "mandelbrot", 10);
		else if (i == 5)
			ret = compare(name, "julia", 5);
		else if (i == 4)
			ret = compare(name, "tree", 4);
	}
	if (ret == 0)
	{
		fr->name_fr = name[0];
		return (0);
	}
	return (ret);
}

int	control_color(char *color, t_info *fr)
{
	size_t	i;
	int		ret;

	ret = -1;
	if (color != NULL)
	{
		i = 0;
		while (color[i] != '\0')
			i++;
		if (i == 6)
			ret = compare(color, "psycho", 6);
		else if (i == 5)
			ret = compare(color, "fuego", 5);
		else if (i == 4)
			ret = compare(color, "lila", 4);
	}
	if (ret == 0)
	{
		fr->color = color[0];
		return (0);
	}
	return (ret);
}

/* normal values are K_re = 0.353 & K_im = 0.288 */
/* values that I like : ./fractol julia lila 0.39 o 0.4, .2 */
int	control_k(char *param, t_info *fr, char t)
{
	double		val;

	if (param != NULL)
	{
		if ((param[0] >= '0' && param[0] <= '9') || param[0] == '.')
			val = atof(param);
		else
			return (-1);
	}
	if (t == 'r')
		fr->K_re = val;
	if (t == 'i')
		fr->K_im = val;
	return (0);
}
