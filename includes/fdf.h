/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:05:26 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/13 15:58:15 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <consts.h>
# include "../libft/libft.h"

typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3d;
typedef struct s_mesh
{
	t_vec3d	**points;
	size_t	width;
	size_t	height;
}	t_mesh;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*title;
	t_mesh	*mesh;
}	t_data;
void	ft_check_map(char *filename);
void	ft_manage_error(char *e_message, unsigned int e_type, t_data *destroy);
void	ft_destroy_data(t_data *data);
void	ft_free_tab(void **tab);
t_data	*ft_init_data(char *filename);
void	ft_init_mesh(char *filename, t_data *data);
size_t	ft_get_width(char *filename, t_data *data);
size_t	ft_get_height(char *filename, t_data *data);
void	ft_hooks(t_data *data);
#endif
