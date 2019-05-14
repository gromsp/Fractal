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
	void    *imgm;
	int     *addr;
	int     *addrm;
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
	int		iter;
}              t_frct;

typedef struct s_cam
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	float	step;
	float	zoom;
	float	cx;
	float	cy;
}              t_cam;

typedef struct	s_core
{
	t_img	*img;
	t_frct	*frct;
	t_cam	*cam;
}				t_core;


void			initjul(t_core *core);
void			initman(t_core *core);
int				control(int press_key, void *param);
t_img			initimg(t_img *img);
void			initcore(t_core *core);
void			mandelbrot(t_core *core);
void			menucolor(t_core *core);
void			menu(t_core *core);
void			julia(t_core *core);
void			draw(t_core *core);
void			graphic(char *av);


#endif