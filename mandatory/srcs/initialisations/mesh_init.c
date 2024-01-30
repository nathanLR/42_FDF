/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:39:31 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 15:21:44 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	ft_get_step(t_mesh *mesh)
{
	if (mesh->width > mesh->height)
		return ((int)floorf((WIDTH - (PADDING * 2)) / mesh->width));
	else
		return ((int)floorf((HEIGHT - (PADDING * 2)) / mesh->height));
}

void	ft_init_mesh(char *filename, t_data *data)
{
	t_mesh	*mesh;

	mesh = (t_mesh *)malloc(sizeof(t_mesh) * 1);
	if (mesh == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	data->mesh = mesh;
	data->mesh->width = ft_get_width(filename, data);
	data->mesh->height = ft_get_height(filename, data);
	data->mesh->step = ft_get_step(mesh);
	ft_malloc_vectors(data);
	ft_fill_mesh(filename, data);
}

void	ft_malloc_vectors(t_data *data)
{
	size_t	size;
	size_t	i;

	size = (data->mesh->width * data->mesh->height);
	i = 0;
	data->mesh->vecs = (t_vec3d **)ft_calloc(size + 1, sizeof(t_vec3d *));
	if (data->mesh->vecs == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	while (i < size)
	{
		data->mesh->vecs[i] = (t_vec3d *)malloc(sizeof(t_vec3d) * 1);
		if (data->mesh->vecs[i] == NULL)
			ft_manage_error(NULL, P_ERROR, data);
		i++;
	}
}

void	ft_fill_mesh(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_manage_error(NULL, P_ERROR, data);
	y = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			break ;
		}
		ft_process_line(y, &i, line, data);
		free(line);
		y++;
	}
}

void	ft_process_line(int y, int *i, char *line, t_data *data)
{
	int		x;
	char	**line_content;
	int		idx;
	t_vec3d	**vecs;
	t_mesh	*m;

	idx = 0;
	x = 0;
	vecs = data->mesh->vecs;
	m = data->mesh;
	line_content = ft_split(line, SPACE);
	if (line_content == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	while (line_content[idx] != NULL)
	{
		vecs[*i]->x = x * m->step;
		vecs[*i]->y = y * m->step;
		vecs[*i]->z = -1 * ft_atoi(line_content[idx]);
		vecs[*i]->color = ft_retrieve_color(line_content[idx], data);
		idx++;
		*i = *i + 1;
		x++;
	}
	ft_free_tab((void **)line_content);
}

t_u_int	ft_retrieve_color(char *vec_index, t_data *data)
{
	char	**vec_index_content;
	t_u_int	color;

	vec_index_content = ft_split(vec_index, ',');
	if (vec_index_content == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	if (ft_tablen(vec_index_content) == 2)
		color = 0xffff0000;
	else
		color = 0xffffffff;
	if (ft_atoi(vec_index_content[0]) > 0)
		color = 0xff0000ff;
	ft_free_tab((void **)vec_index_content);
	return (color);
}
