/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:13:16 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/22 18:25:47 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdio.h>

void	ft_dot(t_data *data, int x_screen, int y_screen, int color)
{
	char		*dst;
	t_mlx_img	*img;
	
	img = data->mlx_img;
	dst = img->addr + (y_screen * img->line_length + x_screen * (img->bpp / 8));
	if (x_screen >= 0 && x_screen <= WIDTH && y_screen >= 0 && y_screen <= HEIGHT)
		*(unsigned int *)dst = color;
}

t_vec3d	*get_point(t_mesh *mesh, int x, int y)
{
	return (mesh->points[x + y * mesh->width]);
}

void	ft_display(t_data *data)
{
	t_mlx_img	*img;
	t_mesh		*mesh;
	size_t		row;
	size_t		col;

	row = 0;
	col = 0;
	mesh = data->mesh;
	img = data->mlx_img;
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bpp / 8));	
	
	while (row < mesh->height)
	{
		while (col < mesh->width)
		{
			if (col < mesh->width -1)
				ft_draw_line(
					get_point(mesh, col, row)->x,
					get_point(mesh, col, row)->z,
					get_point(mesh, col + 1, row)->x,
					get_point(mesh, col + 1, row)->z, data);
			if (row < mesh->height - 1)
				ft_draw_line(
					get_point(mesh, col, row)->x,
					get_point(mesh, col, row)->z,
					get_point(mesh, col, row + 1)->x,
					get_point(mesh, col, row + 1)->z, data);
			col++;
		}
		row++;
		col = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}
