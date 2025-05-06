/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:47 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/06 19:03:46 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* mlx_utils.c */
#include "fractol.h"
#include <stdlib.h>

void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fractol");
	if (!vars->win)
		exit(EXIT_FAILURE);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		exit(EXIT_FAILURE);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_len,
			&vars->endian);
}

void	mlx_pixel_put_image(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = vars->addr + (y * vars->line_len + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}
