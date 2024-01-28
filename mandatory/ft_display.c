/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:13:16 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/27 16:46:00 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdio.h>

void	ft_dot(int x_screen, int y_screen, int color, t_data *data)
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

void	ft_mult_mat4x4(t_vec3d *i, t_vec3d *o, t_mat4x4 *mat)
{
	float	w;

	o->x = i->x * mat->mat[0][0] + i->y * mat->mat[1][0] + i->z * mat->mat[2][0] + mat->mat[3][0];
	o->y = i->x * mat->mat[0][1] + i->y * mat->mat[1][1] + i->z * mat->mat[2][1] + mat->mat[3][1];
	o->z = i->x * mat->mat[0][2] + i->y * mat->mat[1][2] + i->z * mat->mat[2][2] + mat->mat[3][2];
	w = i->x * mat->mat[0][3] + i->y * mat->mat[1][3] + i->z * mat->mat[2][3] + mat->mat[3][3];
	if (w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}

void	ft_display_dots(t_data *data)
{
	t_mlx_img	*img;
	t_mesh		*mesh;
	int			i;

	i = 0;
	mesh = data->mesh;
	img = data->mlx_img;
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bpp / 8));
	while (mesh->points[i] != NULL)
	{
		ft_dot(mesh->points[i]->x, mesh->points[i]->y, mesh->points[i]->color, data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

void	ft_display(t_data *data)
{
	t_mlx_img	*img;
	t_mesh		*mesh;
	size_t		row;
	size_t		col;
	t_vec3d		*out;
	t_vec3d		*out2;

	row = 0;
	col = 0;
	mesh = data->mesh;
	img = data->mlx_img;
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bpp / 8));	
	
	while (row < mesh->height)
	{
		while (col < mesh->width)
		{
			out = get_point(mesh, col, row);
			printf("point: (%.2f;%.2f)\n", out->x, out->y);
			if (col < mesh->width -1)
			{
				out2 = get_point(mesh, col + 1, row);
				ft_draw_line(out->x, out->y, out2->x, out2->y, data);
			/*
				ft_mult_mat4x4(get_point(mesh, col, row), &out, data->p_mat);
				ft_mult_mat4x4(get_point(mesh, col + 1, row), &out2, data->p_mat);
				out.x += 1.0f;
				out.y += 1.0f;
				out2.x += 1.0f;
				out2.y += 1.0f;
				out.x = out.x + (0.5f * (float)WIDTH);
				out.y = out.y + (0.5f * (float)HEIGHT);
				out2.x = out2.x + (0.5f * (float)WIDTH);
				out2.y = out2.y + (0.5f * (float)HEIGHT);
				ft_draw_line(out.x, out.y, out2.x, out2.y, data);
				*/
			}
			if (row < mesh->height - 1)
			{
				out2 = get_point(mesh, col, row + 1);
				ft_draw_line(out->x, out->y, out2->x, out2->y, data);
				/*
				ft_mult_mat4x4(get_point(mesh, col, row), &out, data->p_mat);
				ft_mult_mat4x4(get_point(mesh, col, row + 1), &out2, data->p_mat);
				out.x += 1.0f;
				out.y += 1.0f;
				out2.x += 1.0f;
				out2.y += 1.0f;
				out.x = out.x + (0.5f * (float)WIDTH);
				out.y = out.y + (0.5f * (float)HEIGHT);
				out2.x = out2.x + (0.5f * (float)WIDTH);
				out2.y = out2.y + (0.5f * (float)HEIGHT);
				ft_draw_line(out.x, out.y, out2.x, out2.y, data);
			*/
			}
			col++;
		}
		row++;
		col = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}
