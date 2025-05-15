/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:26:46 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/12 16:43:36 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_color(t_vars *vars, int delta)
{
	int	new_off;

	new_off = vars->color_offset + delta;
	if (new_off < 0)
		new_off = (new_off % MAX_ITER) + MAX_ITER;
	vars->color_offset = new_off % MAX_ITER;
}

int	get_color(t_vars *vars, int iter)
{
	int		i;
	int		r;
	int		g;
	int		b;
	double	t;

	i = (iter + vars->color_offset) % MAX_ITER;
	t = (double)i / (double)MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
