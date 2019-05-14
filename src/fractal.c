/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:09:54 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/26 15:56:13 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int		main(int ag, char **av)
{
	int i;

	i = 0;
	if (ag != 2)
	{
		write (1, "Please, enter fractol:\n-mandelbrot\n-julia\n-tretiy\n", 50);
		return (-1);
	}
	graphic(av[1]);	
}