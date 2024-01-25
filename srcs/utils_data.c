/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:36:00 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:18 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fdf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

#include <stdio.h>

static void	ft_fill_points(char *filename, t_data *data);

void	ft_destroy_data(t_data *data)
{
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->title != NULL)
		free(data->title);
	if (data->mesh != NULL && data->mesh->points != NULL)
		ft_free_tab((void **)data->mesh->points);
	if (data->mesh != NULL)
		free(data->mesh);
	if (data->mlx_img != NULL && data->mlx_img->img != NULL)
		free(data->mlx_img->img);
	if (data->mlx_img != NULL)
		free(data->mlx_img);
	if (data->mouse != NULL)
		free(data->mouse);
	if (data->cam != NULL)
		free(data->cam);
	if (data->p_mat != NULL)
		free(data->p_mat);
	free(data->mlx);
	free(data);
}

void	ft_init_mlx_img(t_data *data)
{
	t_mlx_img	*mlx_img;

	mlx_img = (t_mlx_img *)malloc(sizeof(t_mlx_img) * 1);
	if (mlx_img == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->mlx_img = mlx_img;
	mlx_img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_img->img == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	mlx_img->addr = mlx_get_data_addr(mlx_img->img, &mlx_img->bpp,
		&mlx_img->line_length, &mlx_img->endian);
}

t_data	*ft_init_data(char *filename)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	if (data == NULL)
		ft_manage_error(NULL, P_ERROR, NULL);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->title = ft_strjoin("FDF:nle-roux - ", filename);
	if (data->title == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->title);
	if (data->win == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->mouse = (t_mouse *)malloc(sizeof(t_mouse) * 1);
	if (data->mouse == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->mouse->mouse_down = FALSE;
	data->mouse->prev_x = 0;
	data->mouse->prev_y = 0;
	data->mesh = NULL;
	data->mlx_img = NULL;
	data->cam = NULL;
	data->p_mat = NULL;
	return (data);
}

void	ft_init_mesh(char *filename, t_data *data)
{
	t_vec3d	**points;
	size_t	width;
	size_t	height;
	size_t	size;
	t_mesh	*mesh;

	mesh = (t_mesh *)malloc(sizeof(t_mesh) * 1);
	if (mesh == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->mesh = mesh;
	width = ft_get_width(filename, data);
	height = ft_get_height(filename, data);
	size = (width * height) + 1;
	points = (t_vec3d **)ft_calloc(sizeof(t_vec3d *), size);
	if (points == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	mesh->height = height;
	mesh->width = width;
	mesh->points = points;
	ft_fill_points(filename, data);
}

void	ft_init_cam(t_data *data)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera) * 1);
	if (cam == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->cam = cam;
	cam->ar = (float)WIDTH / (float)HEIGHT;
	cam->fov = 90.0;
	cam->znear = 0.1;
	cam->zfar = 1000.0;
	cam->fovrad = 1.0 / tanf((cam->fov * 0.5) / (180.0 * M_PI));
}

/*static void	ft_fill_mat(t_mat4x4 *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m->mat[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}*/

void	ft_init_projection(t_data *data)
{
	t_mat4x4	*mat;

	mat = (t_mat4x4 *)malloc(sizeof(t_mat4x4) * 1);
	if (mat == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->p_mat = mat;
	mat->mat[0][0] = 0.0, mat->mat[0][1] = 0.0, mat->mat[0][2] = 0.0, mat->mat[0][3] = 0.0;
	mat->mat[1][0] = 0.0, mat->mat[1][1] = 0.0, mat->mat[1][2] = 0.0, mat->mat[1][3] = 0.0;
	mat->mat[2][0] = 0.0, mat->mat[2][1] = 0.0, mat->mat[2][2] = 0.0, mat->mat[2][3] = 0.0;
	mat->mat[3][0] = 0.0, mat->mat[3][1] = 0.0, mat->mat[3][2] = 0.0, mat->mat[3][3] = 0.0;
	mat->mat[0][0] = data->cam->ar * data->cam->fovrad;
	mat->mat[1][1] = data->cam->fovrad;
	mat->mat[2][2] = data->cam->zfar / (data->cam->zfar - data->cam->znear);
	mat->mat[3][2] = (-data->cam->zfar * data->cam->znear) / (data->cam->zfar - data->cam->znear);
	mat->mat[2][3] = 1.0;
	int i = 0, j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			printf("%.2f ", mat->mat[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
}

static void	ft_fill_points(char *filename, t_data *data)
{
	size_t	row;
	size_t	col;
	int		fd;
	char	*line;
	char	**line_content;

	int	i;

	i = 0;
	row = 0;
	col = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_manage_error(NULL, P_ERROR, data);
	while (row < data->mesh->height)
	{
		line = get_next_line(fd);
		line_content = ft_split(line, ' ');
		free(line);
		if (line_content == NULL && close(fd) == 0)
			ft_manage_error(NULL, P_ERROR, data);
		while (col < data->mesh->width)
		{
			data->mesh->points[i] = (t_vec3d *)malloc(sizeof(t_vec3d) * 1);
			if (data->mesh->points[i] == NULL && close(fd) == 0)
				ft_manage_error(NULL, P_ERROR, data);
			data->mesh->points[i]->x = col * 10;
			data->mesh->points[i]->z = row * 10;
			data->mesh->points[i]->y = ft_atoi(*line_content++) * 10;
			col++;
			//data->mesh->points++;
			i++;
		}
		ft_free_tab((void **)(line_content - data->mesh->width));
		row++;
		col = 0;
	}
	line = get_next_line(fd);
	close(fd);
}
