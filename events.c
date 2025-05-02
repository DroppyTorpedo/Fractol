/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:28:56 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 23:28:56 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* events.c */
#include "fractol.h"
#include <stdlib.h>

int key_hook(int key, t_vars *vars)
{
    if (key == KEY_ESC)
        exit(EXIT_SUCCESS);
    else if (key == KEY_LEFT)
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
    else if (key == KEY_PLUS)
        vars->max_iter += ITER_STEP;
    else if (key == KEY_MINUS)
        vars->max_iter = (vars->max_iter > ITER_STEP)
                          ? vars->max_iter - ITER_STEP
                          : vars->max_iter;
    draw_fractal(vars);
    return (0);
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{
    double factor;
    double mouse_r;
    double mouse_i;

    factor = (button == MOUSE_SCROLL_UP)
             ? ZOOM_FACTOR
             : (button == MOUSE_SCROLL_DOWN)
               ? (1.0 / ZOOM_FACTOR)
               : 1.0;
    if (factor == 1.0)
        return (0);
    mouse_r = map_value(x, 0, WIDTH,
                        vars->view.x_min, vars->view.x_max);
    mouse_i = map_value(y, 0, HEIGHT,
                        vars->view.y_min, vars->view.y_max);
    vars->view.x_min = mouse_r + (vars->view.x_min - mouse_r) * factor;
    vars->view.x_max = mouse_r + (vars->view.x_max - mouse_r) * factor;
    vars->view.y_min = mouse_i + (vars->view.y_min - mouse_i) * factor;
    vars->view.y_max = mouse_i + (vars->view.y_max - mouse_i) * factor;
    vars->view.zoom *= factor;
    draw_fractal(vars);
    return (0);
}

void set_hooks(t_vars *vars)
{
    mlx_key_hook(vars->win, key_hook, vars);
    mlx_mouse_hook(vars->win, mouse_hook, vars);
}