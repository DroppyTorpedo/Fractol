/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:30:13 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/12 16:45:51 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
# define MOVE_STEP 0.05
# define ITER_STEP 10
# define ZOOM_FACTOR 1.1

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_A 97
# define KEY_S 115

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct s_view
{
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				zoom;
}						t_view;

enum					e_fract
{
	FRACT_UNKNOWN,
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	TRICORN
};
typedef enum e_fract	t_fract;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	void				*img;
	t_fract				type;
	double				c_r;
	double				c_i;
	t_view				view;
	int					max_iter;
	int					color_offset;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
}						t_vars;

typedef struct s_range
{
	double				min;
	double				max;
}						t_range;

/* utils.c */
int						parse_args(int argc, char **argv, t_vars *vars);
t_fract					parse_type(char *s);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_putstr(char *s);
void					print_usage(void);
double					ft_atof(const char *s);

/* mlx_utils.c */
void					init_mlx(t_vars *vars);
void					mlx_pixel_put_image(t_vars *vars, int x, int y,
							int color);

/* view.c */
void					set_default_view(t_vars *vars);
void					move_view(int key, t_vars *vars);
void					update_view(t_vars *vars, double factor, double mouse_r,
							double mouse_i);

/* draw.c */
double					map_value(double v, t_range src, t_range dst);
void					draw_fractal(t_vars *vars);

/* fractals.c */
int						mandelbrot_iter(t_complex c);
int						julia_iter(t_complex z, t_complex c);
int						burningship_iter(t_complex c);
int						tricorn_iter(t_complex c);

/* color.c */
void					shift_color(t_vars *vars, int delta);
int						get_color(t_vars *vars, int iter);

/* events.c */
int						key_hook(int key, t_vars *vars);
int						mouse_hook(int button, int x, int y, t_vars *vars);
void					set_hooks(t_vars *vars);

#endif
