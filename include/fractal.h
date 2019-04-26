#ifndef FRACTAL
# define FRACTAL

# include "mlx.h"

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_img
{
	void    *mlx;
	void    *win;
	void    *img;
	int     *addr;
	int     bts;
	int     size_line;
	int     endian;
}              t_img;

typedef struct s_frct
{
	char    frct;
	float   zx;
	float   zy;
	float   cx;
	float   cy;
	float   tmp;
}              t_frct;

typedef struct s_cam
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	float	step;
	int		zoom;
}              t_cam;

typedef struct s_core
{
	t_img	*img;
	t_frct	*frct;
	t_cam	*cam;
}              t_core;

t_img	initimg(t_img *img);
void	initcore(t_core *core);
void	mandelbrot(t_core *core);
void	graphic(void);


#endif