/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:48:27 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 15:00:38 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_line(t_vec3d *from_o, t_vec3d *to_o, t_data *data)
{
	t_vec3d	*from;
	t_vec3d	*to;
	int	color;
	int	x;
	int	y;
	int	diff_x;
	int	diff_y;
	int	abs_diff_x;
	int	abs_diff_y;
	int	err_term_x;
	int	err_term_y;
	int	end_x;
	int	end_y;
	
	from = malloc(sizeof(t_vec3d));
	to = malloc(sizeof(t_vec3d));
	ft_project(from_o, from);
	ft_project(to_o, to);
	if (from_o->z < to_o->z)
		color = to_o->color;
	else
		color = from_o->color;
	diff_x = to->x - from->x;
	diff_y = to->y - from->y;
	abs_diff_x = ft_abs(diff_x);
	abs_diff_y = ft_abs(diff_y);
	err_term_x = 2 * abs_diff_y - abs_diff_x;
	err_term_y = 2 * abs_diff_x - abs_diff_y;
	if (abs_diff_y <= abs_diff_x)
	{
		if (diff_x >= 0)
		{
			x = from->x;
			y = from->y;
			end_x = to->x;
		}
		else
		{
			x = to->x;
			y = to->y;
			end_x = from->x;
		}
		//ft_dot(x, y, ft_get_color(from, to, x, y), data);
		ft_dot(x, y, color, data);
		while (x < end_x)
		{
			x++;
			if (err_term_x < 0)
				err_term_x = err_term_x + 2 * abs_diff_y;
			else
			{
				if ((diff_x < 0 && diff_y < 0) || (diff_x > 0 && diff_y > 0))
					y++;
				else
					y--;
				err_term_x = err_term_x + 2 * (abs_diff_y - abs_diff_x);
			}
			//ft_dot(x, y, ft_get_color(from, to, x, y), data);
			ft_dot(x, y, color, data);
		}
	}
	else
	{
		if (diff_y >= 0)
		{
			x = from->x;
			y = from->y;
			end_y = to->y;
		}
		else
		{
			x = to->x;
			y = to->y;
			end_y = from->y;
		}
		//ft_dot(x, y, ft_get_color(from, to, x, y), data);
		ft_dot(x, y, color, data);
		while (y < end_y)
		{
			y++;
			if (err_term_y <= 0)
				err_term_y = err_term_y + 2 * abs_diff_x;
			else
			{
				if ((diff_x < 0 && diff_y < 0) || (diff_x > 0 && diff_y > 0))
					x++;
				else
					x--;
				err_term_y = err_term_y + 2 * (abs_diff_y - abs_diff_y);
			}
			//ft_dot(x, y, ft_get_color(from, to, x, y), data);
			ft_dot(x, y, color, data);
		}
	}
}
