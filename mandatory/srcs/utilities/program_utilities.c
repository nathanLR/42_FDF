/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:58:41 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 09:20:51 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_manage_error(char *e_m, t_type type, t_data *data)
{
	if (data != NULL)
		ft_destroy_data(data);
	if (type == U_ERROR)
		ft_putendl_fd(e_m, STDERR_FILENO);
	else if (type == P_ERROR)
		perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_destroy_data(t_data *data)
{
	if (data->title != NULL)
		free(data->title);
	if (data->mesh != NULL && data->mesh->vecs != NULL)
		ft_free_tab((void **)data->mesh->vecs);
	if (data->mesh != NULL)
		free(data->mesh);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx_img != NULL && data->mlx_img->img != NULL)
		free(data->mlx_img->img);
	if (data->mlx_img != NULL)
		free(data->mlx_img);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}
