/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:51:19 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/04 19:47:02 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int		mandelbrotpart(t_core *core, int k)
{
	while (k < 15 + (5 * core->cam->zoom))
	{
		core->frct->tmp = core->frct->zx * core->frct->zx -
		core->frct->zy * core->frct->zy;
		core->frct->zy = 2 * core->frct->zx *
		core->frct->zy + core->frct->cy;
		core->frct->zx = core->frct->tmp + core->frct->cx;
		if (core->frct->zy * core->frct->zy +
		core->frct->zx * core->frct->zx > (long double)50)
			break ;
		k++;
	}
	return (k);
}

void	mandelcolor(t_core *core, int k, int i, int j)
{
	if (k < 15 + (5 * core->cam->zoom))
		core->img->addr[i + (j * 1000)] = colors(core, k);
	else
		core->img->addr[i + (j * 1000)] = 0x000000;
}

void	mandelbrot(t_core *core)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 1000)
	{
		core->frct->cx = (((long double)i - core->cam->cx) /
		core->cam->step) + core->movex;
		j = 0;
		while (j < 1000)
		{
			core->frct->cy = (((long double)j - core->cam->cy) /
			core->cam->step) + core->movey;
			core->frct->zx = 0.0;
			core->frct->zy = 0.0;
			k = 0;
			k = mandelbrotpart(core, k);
			mandelcolor(core, k, i, j);
			j++;
		}
		i++;
	}
	return ;
}
