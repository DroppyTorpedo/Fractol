/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:30:13 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 23:30:13 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define WIDTH         800
# define HEIGHT        600
# define MAX_ITER      100
# define MOVE_STEP     0.05
# define ITER_STEP     10
# define ZOOM_FACTOR   1.1

/* Keycodes (Mac MLX) */
# define KEY_ESC           53
# define KEY_LEFT          123
# define KEY_RIGHT         124
# define KEY_UP            126
# define KEY_DOWN          125
# define KEY_PLUS          69
# define KEY_MINUS         78

/* Mouse */
# define MOUSE_SCROLL_UP   4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_complex
{
    double    r;
    double    i;
}   t_complex;

typedef struct s_view
{
    double    x_min;
    double    x_max;
    double    y_min;
    double    y_max;
    double    zoom;
}   t_view;

enum e_fract
{
    FRACT_UNKNOWN,
    MANDELBROT,
    JULIA,
    BURNING_SHIP
};
typedef enum e_fract    t_fract;

typedef struct s_vars
{
    void     *mlx;
    void     *win;
    void     *img;
    t_fract   type;
    double    c_r;
    double    c_i;
    t_view    view;
    int       max_iter;
}   t_vars;

/* utils.c */
int     parse_args(int argc, char **argv, t_vars *vars);
int     parse_type(char *s);
int     ft_strcmp(const char *s1, const char *s2);
void    ft_putstr(char *s);
void    print_usage(void);

double  ft_atof(const char *s);

/* mlx_utils.c */
void    init_mlx(t_vars *vars);
void    mlx_pixel_put_image(void *img, int x, int y, int color);

/* view.c */
void    set_default_view(t_vars *vars);

/* draw.c */
void    draw_fractal(t_vars *vars);

/* fractals.c */
int     mandelbrot_iter(t_complex c);
int     julia_iter(t_complex z, t_complex c);
int     burningship_iter(t_complex c);

/* color.c */
int     get_color(int iter);

/* events.c */
int     key_hook(int key, t_vars *vars);
int     mouse_hook(int button, int x, int y, t_vars *vars);
void    set_hooks(t_vars *vars);

#endif