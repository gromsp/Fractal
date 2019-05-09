/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphcore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:15:01 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/29 18:39:09 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void		menucolor(t_core *core)
{
	int i;

	i = 0;
	while(i < 199 * 1000)
	{
		core->img->addrm[i] = 0xA8A8A8;
		i++;
	}
}

void		menu(t_core *core)
{
	mlx_string_put(core->img->mlx, core->img->win, 1, 1, 0x00FF9632, "Menu");
}

void		graphic(void)
{
	t_core	*core;

	if ((core = (t_core *)ft_memalloc(sizeof(t_core))) == NULL)
		exit(0);	
	initcore(core);
	initman(core);
	mandelbrot(core);
	menucolor(core);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->img, 200, 0);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->imgm, 0, 0);
	menu(core);
	mlx_key_hook(core->img->win, control, (void*)(core));
	mlx_loop(core->img->mlx);
}

void		draw(t_core *core)
{
	if (core->frct->frct == 'm')
		mandelbrot(core);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->img, 200, 0);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->imgm, 0, 0);
}