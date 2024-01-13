/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:51:13 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/13 14:24:01 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_get_width(char *filename, t_data *data)
{
	size_t	width;
	int		fd;
	char	*line;
	char	**line_content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_manage_error(NULL, P_ERROR, data);
	line = get_next_line(fd);
	line_content = ft_split(line, ' ');
	free(line);
	close(fd);
	if (line_content == NULL)
		ft_manage_error(NULL, P_ERROR, data);
	width = ft_tablen(line_content);
	ft_free_tab((void **)line_content);
	return (width);
}

size_t	ft_get_height(char *filename, t_data *data)
{
	size_t	height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_manage_error(NULL, P_ERROR, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}
