/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:30 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/04 19:19:54 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	colorswitch(int key, t_core *core)
{
	if (key == 18)
		core->color1 = 0x040a01;
	if (key == 19)
		core->color1 = 0x110000;
	if (key == 20)
		core->color1 = 0x000a0a;
	if (key == 21)
		core->color1 = 0x025677799;
	draw(core);
}

void	pick(int key, t_core *core)
{
	if (key == 12)
		initman(core);
	if (key == 13)
		initjul(core);
	if (key == 14)
	{
		initman(core);
		core->frct->frct = 'b';
	}
	if (key == 15)
	{
		initman(core);
		core->frct->frct = 't';
	}
	draw(core);
}

void	iter(int key, t_core *core)
{
	if (key == 67)
		core->cam->zoom++;
	if (key == 75)
	{
		if (core->cam->zoom > 1)
			core->cam->zoom--;
	}
	draw(core);
}

void	zoom(int key, t_core *core)
{
	if (key == 69 || key == 4)
	{
		core->cam->step *= 2;
	}
	if (key == 78 || key == 5)
	{
		core->cam->step /= 2;
	}
	draw(core);
}
