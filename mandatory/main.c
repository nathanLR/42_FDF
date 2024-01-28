/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:54 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/28 10:58:46 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include <fdf.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		ft_manage_error("Usage: ./fdf [path_to_file].fdf", U_ERROR, NULL);
	ft_check_map(argv[1]);
	data = ft_init_data(argv[1]);
	ft_init_mesh(argv[1], data);
	ft_init_mlx_img(data);
	ft_init_projection(data);
	ft_hooks(data);
	ft_display_dots(data);
	mlx_loop(data->mlx);
}
