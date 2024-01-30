/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:47:10 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 09:20:36 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_data	*ft_init_data(char	*title)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	if (data == NULL)
		ft_manage_error(NULL, P_ERROR, NULL);
	data->title = ft_strjoin("FDF | nle-roux: ", title);
	if (data->title == NULL)
		ft_manage_error(NULL, P_ERROR, NULL);
	data->mesh = NULL;
	data->mlx = NULL;
	data->mlx_img = NULL;
	data->win = NULL;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_manage_error("Usage: ./fdf [path_to_file]", U_ERROR, NULL);
	ft_check_map(argv[1]);
	data = ft_init_data(argv[1]);
	ft_init_mesh(argv[1], data);
	ft_init_mlx(data);
	ft_init_mlx_win(data);
	ft_init_mlx_img(data);
	ft_hooks(data);
	ft_display_mesh(data);
	mlx_loop(data->mlx);
}
