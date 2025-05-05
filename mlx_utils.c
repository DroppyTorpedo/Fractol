/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:47 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/02 13:25:23 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* mlx_utils.c */
#include "fractol.h"
#include <stdlib.h>

static char	*g_addr;
static int	g_bpp;
static int	g_line_len;
static int	g_endian;

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
	g_addr = mlx_get_data_addr(vars->img, &g_bpp, &g_line_len, &g_endian);
}

void	mlx_pixel_put_image(void *img, int x, int y, int color)
{
	char *dst;

	(void)img;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = g_addr + (y * g_line_len + x * (g_bpp / 8));
	*(unsigned int *)dst = color;
}