/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:51:19 by adoyle            #+#    #+#             */
/*   Updated: 2019/05/16 16:50:50 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	burnship(t_core *core)
{
	int i;
	int j;
	int k;
	long double x;
	long double y;
	
	i = 0;
	while(i < 1000)
	{
		x = ((long double)i - core->cam->cx) / core->cam->step;
		j = 0;
		while (j < 1000)
		{
			y = ((long double)j - core->cam->cy) / core->cam->step;
			core->frct->zx = x;
			core->frct->zy = y;
			k = 0;
			while (k < 100 * core->cam->zoom)
			{
				core->frct->tmp = core->frct->zx * core->frct->zx - core->frct->zy * core->frct->zy + x;
        		core->frct->zy = fabsl(2 * core->frct->zx * core->frct->zy)  + y;
				core->frct->zx = fabsl(core->frct->tmp);
				if (core->frct->zy*core->frct->zy + core->frct->zx*core->frct->zx > 4)
					break;
				k++;
			}
			if (k < 100 * core->cam->zoom)
				core->img->addr[i + (j * 1000)] = 0x100045 + k * 0x070500;
			else
				core->img->addr[i + (j * 1000)] = 0x000000;
			j++;			
		}
		i++;
	}
	return ;
}