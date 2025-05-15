/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:24:33 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/12 16:49:07 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_value(double v, t_range src, t_range dst)
{
	return (((v - src.min) / (src.max - src.min)) * (dst.max - dst.min)
		+ dst.min);
}

static int	calculate_iter(t_vars *vars, t_complex point)
{
	if (vars->type == MANDELBROT)
		return (mandelbrot_iter(point));
	if (vars->type == JULIA)
		return (julia_iter(point, (t_complex){vars->c_r, vars->c_i}));
	if (vars->type == BURNING_SHIP)
		return (burningship_iter(point));
	if (vars->type == TRICORN)
		return (tricorn_iter(point));
	else
		return (0);
}

static void	draw_pixel(t_vars *vars, int px, int py)
{
	t_complex	point;
	int			iter;

	point.r = map_value(px, (t_range){0, WIDTH}, (t_range){vars->view.x_min,
			vars->view.x_max});
	point.i = map_value(py, (t_range){0, HEIGHT}, (t_range){vars->view.y_min,
			vars->view.y_max});
	iter = calculate_iter(vars, point);
	mlx_pixel_put_image(vars, px, py, get_color(vars, iter));
}

void	draw_fractal(t_vars *vars)
{
	int	px;
	int	py;

	px = 0;
	while (px < WIDTH)
	{
		py = 0;
		while (py < HEIGHT)
		{
			draw_pixel(vars, px, py);
			py++;
		}
		px++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
