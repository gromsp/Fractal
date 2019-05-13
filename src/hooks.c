/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:30 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/29 18:21:02 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	pick(int key, t_core *core)
{
	if (key == 12)
		initman(core);
	draw(core);
}

void	zoom(int key, t_core *core)
{
	if (key == 69)
	{
		core->cam->zoom = core->cam->zoom * 2;
		core->cam->x0 /= 2;
		core->cam->x1 /= 2;
		core->cam->y0 /= 2;
		core->cam->y1 /= 2;
		core->cam->step = 1000 / (abs(core->cam->x0) + abs(core->cam->x1));
	}
	if (key == 78)
	{
		if (core->cam->zoom > 1)
			core->cam->zoom = core->cam->zoom / 2;
		core->cam->x0 *= 2;
		core->cam->x1 *= 2;
		core->cam->y0 *= 2;
		core->cam->y1 *= 2;
		core->cam->step = 1000 / (abs(core->cam->x0) + abs(core->cam->x1));
	}
	draw(core);
}

void	arrow(int key, t_core *core)
{
	if (key == 1) //vniz
		core->cam->cy += 100;
	if (key == 1) //vverh
		core->cam->cy -= 100;
	if (key == 1) //vpravo
		core->cam->cx += 100;
	if (key == 1) //vlevo
		core->cam->cx -= 100;	
	draw(core);
}

int		control(int press_key, void *param)
{
	t_core	*core;

	core = (t_core*)param;
	// printf("%d\n", press_key); 65421
	if (press_key == 53)
		exit (-2);
	if (press_key == 12 || press_key == 13 || press_key == 14)
		pick(press_key, core);
	if (press_key == 69 || press_key == 78)
		zoom(press_key, core);
	if (press_key == 1 || press_key == 1 || press_key == 1 || press_key == 1)
		arrow(press_key, core);		
}