/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:35:02 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/29 13:17:37 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	ft_bzero_mat(int cols, int rows, float **mat)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < cols)
	{
		while (row < rows)
		{
			mat[col][row] = 0.0f;
			row++;
		}
		col++;
		row = 0;
	}
}

float	**ft_create_mat(int cols, int rows, t_data *data)
{
	float	**mat;
	int		i;

	i = 0;
	mat = (float **)ft_calloc(cols + 1, sizeof(float *));
	if (mat == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	while (i < cols)
	{
		mat[i] = (float *)ft_calloc(rows + 1, sizeof(float));
		if (mat[i] == NULL)
			ft_manage_error(NULL, P_ERROR, data);
		i++;
	}
	ft_bzero_mat(cols, rows, mat);
	return (mat);
}

void	ft_fill_mat(t_type type, t_data *data)
{
	if (type == ISOMETRIQUE)
	{
		data->proj->mat[0][0] = sqrtf(2) / 2;
		data->proj->mat[1][0] = -(sqrtf(2) / 2);
		data->proj->mat[0][1] = sqrtf(6) / 6;
		data->proj->mat[1][1] = sqrtf(6) / 6;
		data->proj->mat[2][1] = -(sqrtf(6) / 3);
		data->proj->mat[0][2] = sqrtf(3) / 3;
		data->proj->mat[1][2] = sqrtf(3) / 3;
		data->proj->mat[2][2] = sqrtf(3) / 3;
	}
}

void	ft_mult_mat_3x3(t_vec3d *i, t_vec3d *o, t_proj *p)
{
	o->x = i->x * p->mat[0][0] + i->y * p->mat[0][1] + i->z * p->mat[0][2];
	o->y = i->x * p->mat[1][0] + i->y * p->mat[1][1] + i->z * p->mat[1][2];
	o->z = i->x * p->mat[2][0] + i->y * p->mat[2][1] + i->z * p->mat[2][2];
	o->color = i->color;
}
