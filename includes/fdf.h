/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:05:26 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/12 19:37:08 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <consts.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3d;
void	ft_check_map(char *filename);
void	ft_manage_error(char *e_message, unsigned int e_type, t_data *to_destroy);
void	ft_destroy_data(t_data *data);
void	ft_free_tab(char **tab);
#endif
