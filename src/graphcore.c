/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphcore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:15:01 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/26 18:20:46 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void		graphic(void)
{
	t_core	*core;

	if ((core = (t_core *)ft_memalloc(sizeof(t_core))) == NULL)
		exit(0);	
	initcore(core);
	mandelbrot(core);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->img, 0, 0);
	mlx_loop(core->img->mlx);
}