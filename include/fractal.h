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
	int		jm;
	long double   zx;
	long double   zy;
	long double   cx;
	long double   cy;
	long double   cx1;
	long double   cy1;
	long double   tmp;
	int		iter;
}              t_frct;

typedef struct s_cam
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	step; //zoom
	double	zoom; //iter
	int	cx;
	int	cy;
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
int				mouse_move(int x, int y, void *param);
int				controlms(int key, int x, int y, void *param);
t_img			initimg(t_img *img);
void			initcore(t_core *core);
void			burnship(t_core *core);
void			mandelbrot(t_core *core);
void			menucolor(t_core *core);
void			menu(t_core *core);
void			julia(t_core *core);
void			draw(t_core *core);
void			graphic(char *av);


#endif