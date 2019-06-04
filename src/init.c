/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:47:07 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/04 19:21:38 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	initjul(t_core *core)
{
	core->frct->frct = 'j';
	core->cam->x0 = -2;
	core->cam->x1 = 2;
	core->cam->y0 = -2;
	core->cam->y1 = 2;
	core->cam->zoom = 1;
	core->cam->step = 250;
	core->cam->cx = 500;
	core->cam->cy = 500;
	core->frct->jm = 1;
	core->frct->cx1 = 0.8;
	core->frct->cy1 = 0.156;
	core->movey = 0;
	core->movex = 0;
}

void	initman(t_core *core)
{
	core->frct->frct = 'm';
	core->cam->x0 = -2;
	core->cam->x1 = 2;
	core->cam->y0 = -2;
	core->cam->y1 = 2;
	core->cam->zoom = 1;
	core->cam->step = 250;
	core->cam->cx = 500;
	core->cam->cy = 500;
	core->color = 0x100045;
	core->movey = 0;
	core->movex = 0;
}

t_img	initimg(t_img *img)
{
	char	*s;
	char	*m;

	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, 1000, 1000);
	img->imgm = mlx_new_image(img->mlx, 199, 1000);
	img->win = mlx_new_window(img->mlx, 1200, 1000, "42");
	s = mlx_get_data_addr(img->img, &(img->bts),
	&(img->size_line), &(img->endian));
	m = mlx_get_data_addr(img->imgm, &(img->bts),
	&(img->size_line), &(img->endian));
	img->addr = (int*)s;
	img->addrm = (int*)m;
	return (*img);
}

void	initcore(t_core *core)
{
	t_img	*img;
	t_frct	*frct;
	t_cam	*cam;

	if ((img = (t_img *)ft_memalloc(sizeof(t_img))) == NULL)
		exit(0);
	core->img = img;
	*img = initimg(img);
	if ((frct = (t_frct *)ft_memalloc(sizeof(t_frct))) == NULL)
		exit(0);
	core->frct = frct;
	if ((cam = (t_cam *)ft_memalloc(sizeof(t_cam))) == NULL)
		exit(0);
	core->cam = cam;
	core->color1 = 0x040a01;
	core->movex = 0;
	core->movey = 0;
}
