/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphcore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:15:01 by adoyle            #+#    #+#             */
/*   Updated: 2019/05/28 19:30:09 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void		menu(t_core *core)
{
	int i;

	i = 0;
	while(i < 199 * 1000)
	{
		core->img->addrm[i] = 0x303040;
		i++;
	}
}

void		text(t_core *core)
{
	mlx_string_put(core->img->mlx, core->img->win, 10, 10, 0xAF5555, "Menu:");
	mlx_string_put(core->img->mlx, core->img->win, 10, 30, 0xAF5555, "Switch Fractal:");
	mlx_string_put(core->img->mlx, core->img->win, 10, 50, 0xAF5555, "q - Mandelbrot");
	mlx_string_put(core->img->mlx, core->img->win, 10, 70, 0xAF5555, "w - Julia");
	mlx_string_put(core->img->mlx, core->img->win, 10, 90, 0xAF5555, "e - Burningship");
	mlx_string_put(core->img->mlx, core->img->win, 10, 110, 0xAF5555, "r - Tricorn");
	mlx_string_put(core->img->mlx, core->img->win, 10, 120, 0xAF5555, "__________________");
	mlx_string_put(core->img->mlx, core->img->win, 10, 140, 0xAF5555, "Controls:");
	mlx_string_put(core->img->mlx, core->img->win, 10, 160, 0xAF5555, "Move: < > ^ v");
	mlx_string_put(core->img->mlx, core->img->win, 10, 180, 0xAF5555, "Zoom: + -");
	mlx_string_put(core->img->mlx, core->img->win, 10, 200, 0xAF5555, "Zoom: wheel mouse");
	mlx_string_put(core->img->mlx, core->img->win, 10, 220, 0xAF5555, "Iteration: * /");
	mlx_string_put(core->img->mlx, core->img->win, 10, 230, 0xAF5555, "__________________");
	mlx_string_put(core->img->mlx, core->img->win, 10, 250, 0xAF5555, "Mouse mode: m");
	mlx_string_put(core->img->mlx, core->img->win, 10, 260, 0xAF5555, "__________________");
	mlx_string_put(core->img->mlx, core->img->win, 10, 280, 0xAF5555, "Colors:");
	mlx_string_put(core->img->mlx, core->img->win, 10, 300, 0xAF5555, "1: Green");
	mlx_string_put(core->img->mlx, core->img->win, 10, 320, 0xAF5555, "2: Red");
	mlx_string_put(core->img->mlx, core->img->win, 10, 340, 0xAF5555, "3: Blue");
	mlx_string_put(core->img->mlx, core->img->win, 10, 360, 0xAF5555, "4: Psyho");
}

void		graphic(char *av)
{
	t_core	*core;

	if ((core = (t_core *)ft_memalloc(sizeof(t_core))) == NULL)
		exit(0);	
	initcore(core);
	core->color1 = 0x040a01;
	core->movex = 0;
	core->movey = 0;
	if (av[0] == 'm')
		initman(core);
	if (av[0] == 'j')
		initjul(core);
	if (av[0] == 'b')
	{
		initman(core);
		core->frct->frct = 'b';
	}
	if (av[0] == 't')
	{
		initman(core);
		core->frct->frct = 't';
	}
	draw(core);
	mlx_key_hook(core->img->win, control, (void*)(core));
	mlx_mouse_hook(core->img->win, controlms, (void*)(core));
	mlx_hook(core->img->win, 6, 0, mouse_move, (void*)(core));
	mlx_loop(core->img->mlx);
}

void		draw(t_core *core)
{
	mlx_clear_window(core->img->mlx, core->img->win);
	if (core->frct->frct == 'm')
		mandelbrot(core);
	if (core->frct->frct == 'j')
		julia(core);
	if (core->frct->frct == 'b')
		burnship(core);
	if (core->frct->frct == 't')
		tricorn(core);
	menu(core);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->img, 200, 0);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->imgm, 0, 0);
	text(core);
}