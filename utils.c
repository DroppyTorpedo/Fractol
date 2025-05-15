/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:22:48 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/12 16:16:59 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

double	ft_atof(const char *s)
{
	double	result;
	double	sign;
	double	frac;
	double	divider;

	result = 0.0;
	sign = 1.0;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1.0;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	frac = 0.0;
	divider = 1.0;
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			frac = frac * 10 + (*s++ - '0');
			divider *= 10;
		}
		result += frac / divider;
	}
	return (result * sign);
}

t_fract	parse_type(char *s)
{
	if (ft_strcmp(s, "mandelbrot") == 0)
		return (MANDELBROT);
	if (ft_strcmp(s, "julia") == 0)
		return (JULIA);
	if (ft_strcmp(s, "burningship") == 0)
		return (BURNING_SHIP);
	if (ft_strcmp(s, "tricorn") == 0)
		return (TRICORN);
	return (FRACT_UNKNOWN);
}

void	print_usage(void)
{
	ft_putstr("Usage: ./fractol <fractale> [<re> <im>]\n");
	ft_putstr("Fractales possibles:\n");
	ft_putstr("  mandelbrot\n");
	ft_putstr("  julia <re> <im>\n");
	ft_putstr("  burningship\n");
}
