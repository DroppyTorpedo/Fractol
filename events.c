/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:28:56 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/06 19:19:33 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* events.c */
#include "fractol.h"
#include <stdlib.h>

int	key_hook(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP
		|| key == KEY_DOWN)
		move_view(key, vars);
	else if (key == KEY_PLUS)
		vars->max_iter += ITER_STEP;
	else if (key == KEY_MINUS)
	{
		if (vars->max_iter > ITER_STEP)
			vars->max_iter -= ITER_STEP;
	}
	draw_fractal(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	factor;
	double	mouse_r;
	double	mouse_i;

	if (button == MOUSE_SCROLL_UP)
		factor = ZOOM_FACTOR;
	else if (button == MOUSE_SCROLL_DOWN)
		factor = 1.0 / ZOOM_FACTOR;
	else
		factor = 1.0;
	if (factor == 1.0)
		return (0);
	mouse_r = map_value(x, (t_range){0, WIDTH}, (t_range){vars->view.x_min,
			vars->view.x_max});
	mouse_i = map_value(y, (t_range){0, HEIGHT}, (t_range){vars->view.y_min,
			vars->view.y_max});
	update_view(vars, factor, mouse_r, mouse_i);
	draw_fractal(vars);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, 0L, close_window, vars);
}
