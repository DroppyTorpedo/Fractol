/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:25:48 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 23:25:48 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(t_complex c)
{
	t_complex	z;
	int			i;
	double		tmp;

	z.r = 0.0;
	z.i = 0.0;
	i = 0;
	while (i < MAX_ITER && (z.r * z.r + z.i * z.i) <= 4.0)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		i++;
	}
	return (i);
}

int	julia_iter(t_complex z, t_complex c)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < MAX_ITER && (z.r * z.r + z.i * z.i) <= 4.0)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		i++;
	}
	return (i);
}

int	burningship_iter(t_complex c)
{
	t_complex z;
	int i;

	z.r = 0.0;
	z.i = 0.0;
	i = 0;
	while (i < MAX_ITER && (z.r * z.r + z.i * z.i) <= 4.0)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		double tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		i++;
	}
	return (i);
}