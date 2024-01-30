/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:16:38 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 15:00:53 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_display_mesh(t_data *data)
{
	int		i;
	t_mesh	*mesh;
	size_t	col;
	size_t	row;
	//t_vec3d	from;
	//t_vec3d	to;

	i = 0;
	col = 0;
	row = 0;
	mesh = data->mesh;
	ft_bzero(data->mlx_img->addr, WIDTH * HEIGHT * (data->mlx_img->bpp / 8));
	while (mesh->vecs[i] != NULL)
	{
	/*
		ft_project(mesh->vecs[i], &from);
		if (col < mesh->width - 1)
		{
			ft_project(mesh->vecs[i + 1], &to);
			ft_draw_line(&from, &to, data);
		}
		if (row < mesh->height - 1)
		{
			ft_project(mesh->vecs[i + mesh->width], &to);
			ft_draw_line(&from, &to, data);
		}
	*/
		if (col < mesh->width - 1)
			ft_draw_line(mesh->vecs[i], mesh->vecs[i + 1], data);
		if (row < mesh->height - 1)
			ft_draw_line(mesh->vecs[i], mesh->vecs[i + mesh->width], data);
		i++;
		col++;
		if (col == mesh->width)
		{
			col = 0;
			row++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->mlx_img->img, 0, 0);
}

void	ft_dot(int x_screen, int y_screen, int color, t_data *data)
{
	char		*pos;
	t_mlx_img	*img;

	img = data->mlx_img;
	pos = img->addr + (y_screen * img->line_length + x_screen * (img->bpp / 8));
	if (x_screen >= 0 && x_screen <= WIDTH
		&& y_screen >= 0 && y_screen <= HEIGHT)
	{
		*(unsigned int *)pos = color;
	}
}

int	ft_get_color(t_vec3d *from, t_vec3d *to, int x, int y)
{
	(void)from;
	(void)to;
	(void)x;
	(void)y;
	return (0xffffffff);
}
