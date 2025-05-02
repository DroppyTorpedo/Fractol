/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:24:33 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 23:24:33 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double map_value(double v, double min1, double max1,
                        double min2, double max2)
{
    return ((v - min1) / (max1 - min1)) * (max2 - min2) + min2;
}

void draw_fractal(t_vars *vars)
{
    int      px;
    int      py;
    t_complex point;
    int      iter;

    px = 0;
    while (px < WIDTH)
    {
        py = 0;
        while (py < HEIGHT)
        {
            point.r = map_value(px, 0, WIDTH,
                                vars->view.x_min, vars->view.x_max);
            point.i = map_value(py, 0, HEIGHT,
                                vars->view.y_min, vars->view.y_max);
            if (vars->type == MANDELBROT)
                iter = mandelbrot_iter(point);
            else if (vars->type == JULIA)
                iter = julia_iter(point, (t_complex){vars->c_r, vars->c_i});
            else
                iter = burningship_iter(point);
            mlx_pixel_put_image(vars->img, px, py,
                                get_color(iter));
            py++;
        }
        px++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}