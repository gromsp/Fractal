/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:51:19 by adoyle            #+#    #+#             */
/*   Updated: 2019/05/16 18:11:22 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	julia(t_core *core)
{
	int i;
	int j;
	int k;
	
	i = 0;
	while(i < 1000)
	{
		core->frct->cx = ((long double)i - core->cam->cx) / core->cam->step;
		j = 0;
		while (j < 1000)
		{
			core->frct->cy = ((long double)j - core->cam->cy) / core->cam->step;
			core->frct->zx = core->frct->cx;
			core->frct->zy = core->frct->cy;
			k = 0;
			while (k < 50 * core->cam->zoom)
			{
				core->frct->tmp = core->frct->zx * core->frct->zx - core->frct->zy * core->frct->zy;
        		core->frct->zy = 2 * core->frct->zx * core->frct->zy + core->frct->cx1;
				core->frct->zx = core->frct->tmp - core->frct->cy1;
				if (core->frct->zy*core->frct->zy + core->frct->zx*core->frct->zx > 4)
					break;
				k++;
			}
			if (k < 50 * core->cam->zoom)
				core->img->addr[i + (j * 1000)] = 0x100045 + k * 0x040a01;
			else
				core->img->addr[i + (j * 1000)] = 0x000000;
			j++;			
		}
		i++;
	}
	return ;
}