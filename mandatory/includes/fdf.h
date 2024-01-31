/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:29:36 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 13:57:17 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <libft.h>
# include <consts.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef unsigned int	t_type;
typedef unsigned int	t_u_int;
typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
	t_u_int	color;
}	t_vec3d;
typedef struct s_mesh
{
	t_vec3d	**vecs;
	size_t	width;
	size_t	height;
	int		step;
}	t_mesh;
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
	char		*title;
	t_mesh		*mesh;
	void		*mlx;
	t_mlx_img	*mlx_img;
	void		*win;
}	t_data;
/* program utilities */
void	ft_manage_error(char *e_m, t_type type, t_data *data);
void	ft_destroy_data(t_data *data);
/* file utilities */
void	ft_check_map(char *filename);
int		ft_file_exists(char *filename);
void	ft_file_not_empty(int fd);
void	ft_check_content(int fd);
/* mesh utilities */
size_t	ft_get_width(char *filename, t_data *data);
size_t	ft_get_height(char *filename, t_data *data);
/* projection utilities */
void	ft_project(t_vec3d *i, t_vec3d *o);
/* draw utilities */
void	ft_display_mesh(t_data *data);
void	ft_dot(int x_screen, int y_screen, int color, t_data *data);
void	ft_draw_line(t_vec3d *from, t_vec3d *to, t_data *data);
int		ft_get_color(t_vec3d *from, t_vec3d *to, int x, int y);
/* init mesh */
void	ft_init_mesh(char *filename, t_data *data);
void	ft_malloc_vectors(t_data *data);
void	ft_fill_mesh(char *filename, t_data *data);
void	ft_process_line(int y, int *i, char *line, t_data *data);
t_u_int	ft_retrieve_color(char *vec_index, t_data *data);
/* init projection */
/* init mlx */
void	ft_init_mlx(t_data *data);
void	ft_init_mlx_img(t_data *data);
void	ft_init_mlx_win(t_data *data);
/* input handle */
void	ft_hooks(t_data *data);
int		ft_key_handler(int key, t_data *data);
int		ft_exit_program(t_data *data);
#endif
