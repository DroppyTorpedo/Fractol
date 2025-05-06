/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:31:29 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/06 19:19:48 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default_view(t_vars *vars)
{
	vars->view.x_min = -2.0;
	vars->view.x_max = 1.0;
	vars->view.y_min = -1.2;
	vars->view.y_max = 1.2;
	vars->view.zoom = 1.0;
	vars->max_iter = MAX_ITER;
}

void	move_view(int key, t_vars *vars)
{
	if (key == KEY_LEFT)
	{
		vars->view.x_min -= MOVE_STEP / vars->view.zoom;
		vars->view.x_max -= MOVE_STEP / vars->view.zoom;
	}
	else if (key == KEY_RIGHT)
	{
		vars->view.x_min += MOVE_STEP / vars->view.zoom;
		vars->view.x_max += MOVE_STEP / vars->view.zoom;
	}
	else if (key == KEY_UP)
	{
		vars->view.y_min -= MOVE_STEP / vars->view.zoom;
		vars->view.y_max -= MOVE_STEP / vars->view.zoom;
	}
	else if (key == KEY_DOWN)
	{
		vars->view.y_min += MOVE_STEP / vars->view.zoom;
		vars->view.y_max += MOVE_STEP / vars->view.zoom;
	}
}

void	update_view(t_vars *vars, double factor, double mouse_r, double mouse_i)
{
	vars->view.x_min = mouse_r + (vars->view.x_min - mouse_r) * factor;
	vars->view.x_max = mouse_r + (vars->view.x_max - mouse_r) * factor;
	vars->view.y_min = mouse_i + (vars->view.y_min - mouse_i) * factor;
	vars->view.y_max = mouse_i + (vars->view.y_max - mouse_i) * factor;
	vars->view.zoom *= factor;
}
