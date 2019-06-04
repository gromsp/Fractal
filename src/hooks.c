/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:30 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/04 19:21:17 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	arrow(int key, t_core *core)
{
	if (key == 125)
		core->movey -= (100 / core->cam->step);
	if (key == 126)
		core->movey += (100 / core->cam->step);
	if (key == 124)
		core->movex -= (100 / core->cam->step);
	if (key == 123)
		core->movex += (100 / core->cam->step);
	draw(core);
}

void	mouseswitch(t_core *core)
{
	if (core->frct->jm == 1)
		core->frct->jm = 0;
	else
		core->frct->jm = 1;
}

int		control(int press_key, void *param)
{
	t_core	*core;

	core = (t_core*)param;
	if (press_key == 53)
		exit(-2);
	if (press_key == 12 || press_key == 13 ||
	press_key == 14 || press_key == 15)
		pick(press_key, core);
	if (press_key == 69 || press_key == 78)
		zoom(press_key, core);
	if (press_key == 125 || press_key == 126 ||
	press_key == 124 || press_key == 123)
		arrow(press_key, core);
	if (press_key == 75 || press_key == 67)
		iter(press_key, core);
	if (press_key == 46)
		mouseswitch(core);
	if (press_key == 18 || press_key == 19 ||
	press_key == 20 || press_key == 21)
		colorswitch(press_key, core);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_core	*core;

	core = (t_core*)param;
	if (core->frct->jm == 1)
	{
		if (x > 200 && x < 1200)
			core->frct->cx1 = ((long double)x - 200) / 1000;
		if (y > 0 && y < 1000)
			core->frct->cy1 = (long double)y / 1000;
	}
	draw(core);
	return (0);
}

int		controlms(int key, int x, int y, void *param)
{
	t_core	*core;

	core = (t_core*)param;
	if (key == 4 || key == 5)
		zoom(key, core);
	return (0);
}
