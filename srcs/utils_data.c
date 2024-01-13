/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:36:00 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/13 17:38:27 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fdf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

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
	free(data->mlx);
	free(data);
}

void	ft_free_tab(void **tab)
{
	char	**tmp;
	
	tmp = (char **)tab;
	while (*tmp)
		free(*tmp++);
	free(tab);
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
	data->mesh = NULL;
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
			data->mesh->points[i]->x = col;
			data->mesh->points[i]->y = row;
			data->mesh->points[i]->z = ft_atoi(*line_content++);
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
