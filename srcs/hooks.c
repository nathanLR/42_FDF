/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:49:41 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/14 11:13:42 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fdf.h>

static int	ft_exit_program(t_data *data)
{
	ft_destroy_data(data);
	exit(EXIT_SUCCESS);
}

static int	key_handler(int key, t_data *data)
{
	if (key == KEY_ESC)
		return (ft_exit_program(data));
	return (TRUE);
}

void	ft_hooks(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 1L << 0, key_handler, data);
	mlx_hook(data->win, ON_DESTROY, 0, ft_exit_program, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 1L << 2, ft_mouse_press, data);
	mlx_hook(data->win, ON_MOUSEUP, 1L << 3, ft_mouse_press, data);
	mlx_hook(data->win, ON_MOUSEMOVE, 1L << 6, ft_mouse_move, data);
}
