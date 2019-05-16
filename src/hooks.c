/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:30 by adoyle            #+#    #+#             */
/*   Updated: 2019/05/16 18:34:51 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	pick(int key, t_core *core)
{
	if (key == 12)
		initman(core);
	if (key == 13)
		initjul(core);
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

void	arrow(int key, t_core *core)
{
	if (key == 125) //vniz
		core->cam->cy += 100;
	if (key == 126) //vverh
		core->cam->cy -= 100;
	if (key == 124) //vpravo
		core->cam->cx += 100;
	if (key == 123) //vlevo
		core->cam->cx -= 100;	
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
		exit (-2);
	if (press_key == 12 || press_key == 13 || press_key == 14)
		pick(press_key, core);
	if (press_key == 69 || press_key == 78)
		zoom(press_key, core);
	if (press_key == 125 || press_key == 126 || press_key == 124 || press_key == 123)
		arrow(press_key, core);
	if (press_key == 75 || press_key == 67)
		iter(press_key, core);
	if (press_key == 46)
		mouseswitch(core);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_core	*core;

	core = (t_core*)param;
	// printf("%d\n", x);
	if (core->frct->jm == 1)
	{	if (x > 200 && x < 1200)
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