/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:52:31 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/04 19:59:10 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*imgm;
	int		*addr;
	int		*addrm;
	int		bts;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_frct
{
	char			frct;
	int				jm;
	long double		zx;
	long double		zy;
	long double		cx;
	long double		cy;
	long double		cx1;
	long double		cy1;
	long double		tmp;
	int				iter;
}				t_frct;

typedef struct	s_cam
{
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	double		step;
	double		zoom;
	int			cx;
	int			cy;
}				t_cam;

typedef struct	s_core
{
	t_img	*img;
	t_frct	*frct;
	t_cam	*cam;
	int		color;
	int		color1;
	double	movex;
	double	movey;
}				t_core;

int				colors(t_core *core, int k);
void			initjul(t_core *core);
void			initman(t_core *core);
void			zoom(int key, t_core *core);
void			iter(int key, t_core *core);
void			pick(int key, t_core *core);
void			colorswitch(int key, t_core *core);
int				control(int press_key, void *param);
int				mouse_move(int x, int y, void *param);
int				controlms(int key, int x, int y, void *param);
t_img			initimg(t_img *img);
void			initcore(t_core *core);
void			tricorn(t_core *core);
void			burnship(t_core *core);
void			mandelbrot(t_core *core);
void			menucolor(t_core *core);
void			menu(t_core *core);
void			julia(t_core *core);
void			draw(t_core *core);
void			graphic(char *av);

#endif
