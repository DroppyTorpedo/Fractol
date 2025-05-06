/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:21:37 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 23:21:37 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(int argc, char **argv, t_vars *vars)
{
	if (argc < 2)
		return (0);
	vars->type = parse_type(argv[1]);
	if (vars->type == FRACT_UNKNOWN)
		return (0);
	if (vars->type == JULIA)
	{
		if (argc != 4)
			return (0);
		vars->c_r = ft_atof(argv[2]);
		vars->c_i = ft_atof(argv[3]);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!parse_args(argc, argv, &vars))
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	init_mlx(&vars);
	set_default_view(&vars);
	draw_fractal(&vars);
	set_hooks(&vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
