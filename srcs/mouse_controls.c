/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:06:57 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/14 11:35:25 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include "../libft/libft.h"

int	ft_mouse_press(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_LEFT)
	{
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
		if (data->mouse->mouse_down == FALSE)
			data->mouse->mouse_down = TRUE;
		else
			data->mouse->mouse_down = FALSE;
	}
	return (TRUE);
}

int	ft_mouse_move(int x, int y, t_data *data)
{
	if (data->mouse->mouse_down == TRUE)
	{
		ft_printf("x: %d, y: %d\n", x, y);
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
	}
	return (TRUE);
}
