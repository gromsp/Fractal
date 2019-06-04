/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:51:19 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/04 19:40:50 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int		colors(t_core *core, int k)
{
	k = core->color + (k / 4) * core->color1;
	return (k);
}

int		burnshippart1(t_core *core, int k, long double x, long double y)
{
	while (k < 20 + (5 * core->cam->zoom))
	{
		core->frct->tmp = core->frct->zx * core->frct->zx -
		core->frct->zy * core->frct->zy + x;
		core->frct->zy = fabsl(2 * core->frct->zx * core->frct->zy) + y;
		core->frct->zx = fabsl(core->frct->tmp);
		if (core->frct->zy * core->frct->zy +
			core->frct->zx * core->frct->zx > 4)
			break ;
		k++;
	}
	return (k);
}

void	colorship(t_core *core, int i, int j, int k)
{
	if (k < 20 + (5 * core->cam->zoom))
		core->img->addr[i + (j * 1000)] = colors(core, k);
	else
		core->img->addr[i + (j * 1000)] = 0x000000;
}

void	burnship(t_core *core)
{
	int			i;
	int			j;
	int			k;
	long double x;
	long double y;

	i = 0;
	while (i < 1000)
	{
		x = (((long double)i - core->cam->cx) / core->cam->step) + core->movex;
		j = 0;
		while (j < 1000)
		{
			y = (((long double)j - core->cam->cy) /
				core->cam->step) + core->movey;
			core->frct->zx = x;
			core->frct->zy = y;
			k = 0;
			k = burnshippart1(core, k, x, y);
			colorship(core, i, j, k);
			j++;
		}
		i++;
	}
	return ;
}
