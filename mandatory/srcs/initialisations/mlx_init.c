/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:21:49 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/29 09:24:37 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_manage_error(NULL, P_ERROR, data);
}

void	ft_init_mlx_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->title);
	if (data->win == NULL)
		ft_manage_error(NULL, P_ERROR, data);
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
	if (mlx_img->addr == NULL)
		ft_manage_error(NULL, P_ERROR, data);
}
