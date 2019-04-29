/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:47:07 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/29 16:51:26 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

t_img	initimg(t_img *img)
{
	char	*s;
	char	*m;
	
	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, 1000, 1000);
	img->imgm = mlx_new_image(img->mlx, 199, 1000);
	img->win = mlx_new_window(img->mlx, 1200, 1000, "42");
	s = mlx_get_data_addr(img->img, &(img->bts), &(img->size_line), &(img->endian));
	m = mlx_get_data_addr(img->imgm, &(img->bts), &(img->size_line), &(img->endian));
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
}