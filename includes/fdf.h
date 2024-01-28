/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:05:26 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/28 11:02:43 by nle-roux         ###   ########.fr       */
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
	int		color;
}	t_vec3d;
typedef struct s_mesh
{
	t_vec3d	**points;
	size_t	width;
	size_t	height;
}	t_mesh;
typedef struct s_mat
{
	float	**;
}	t_mat;
typedef struct s_mouse
{
	t_bool	mouse_down;
	int		prev_x;
	int		prev_y;
}	t_mouse;
typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_img;
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*title;
	t_mesh		*mesh;
	t_mlx_img	*mlx_img;
	t_mouse		*mouse;
	t_mat		*p_mat;
}	t_data;
void	ft_check_map(char *filename);
void	ft_manage_error(char *e_message, unsigned int e_type, t_data *destroy);
void	ft_destroy_data(t_data *data);
t_data	*ft_init_data(char *filename);
void	ft_init_mesh(char *filename, t_data *data);
size_t	ft_get_width(char *filename, t_data *data);
size_t	ft_get_height(char *filename, t_data *data);
void	ft_hooks(t_data *data);
void	ft_init_mlx_img(t_data *data);
int		ft_mouse_move(int x, int y, t_data *data);
int		ft_mouse_press(int button, int x, int y, t_data *data);
void	ft_display(t_data *data);
void	ft_display_dots(t_data *data);
void	ft_init_projection(t_data *data);
void	ft_draw_line(int x1, int y1, int x2, int y2, t_data *data);
void	ft_dot(int x_screen, int y_screen, int color, t_data *data);
#endif
