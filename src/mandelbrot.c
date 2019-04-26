/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:51:19 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/26 18:19:37 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	mandelbrot(t_core *core)
{
	float zx, zy, cx, cy, tmp;
	int i, j, k, m;
	i = 0;
	while(i < 1000)
	{
		cx = ((float)i - 750) / 400.0;
		j = 0;
		while (j < 1000)
		{
			cy = ((float)j - 500) / 400.0;
			zx = zy = 0.0;
			k = 0;
			while (k < 300)
			{
				tmp = zx * zx - zy * zy;
        		zy = 2 * zx * zy  + cy;
				zx = tmp + cx;
				if (zy*zy + zx*zx > 1.0E16)
					break;
				k++;
			}
			if (k < 300)
			{
				m = k%8 + 1;
				core->img->addr[i + (j * 1000)] = 0x4CB1F0 + k * 0x0000ff; 
			}
			else
			{
				core->img->addr[i + (j * 1000)] = 0x000000;
			}
			j++;			
		}
		i++;
	}
	return ;
}