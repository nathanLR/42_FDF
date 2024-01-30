/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:44:16 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/29 13:50:11 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_hooks(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 1L << 0, ft_key_handler, data);
	mlx_hook(data->win, ON_DESTROY, 0, ft_exit_program, data);
}

int	ft_key_handler(int key, t_data *data)
{
	if (key == KEY_ESC)
		return (ft_exit_program(data));
	return (TRUE);
}

int	ft_exit_program(t_data *data)
{
	ft_destroy_data(data);
	exit(EXIT_SUCCESS);
}
