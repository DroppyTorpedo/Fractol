/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:31:29 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 23:31:29 by rnorvene         ###   ########.fr       */
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