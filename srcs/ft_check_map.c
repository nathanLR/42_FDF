/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:46 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/13 18:41:07 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include <fdf.h>
#include <fcntl.h>
#include <unistd.h>

static int	ft_file_exists(char *filename);
static void	ft_file_not_empty(int fd);
static void	ft_check_content(int fd);
static void	ft_clean_exit(int fd, char *e_error, unsigned int e_type);

void	ft_check_map(char *filename)
{
	int	fd;

	fd = ft_file_exists(filename);
	ft_file_not_empty(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_manage_error(NULL, P_ERROR, NULL);
	ft_check_content(fd);
}

static int	ft_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_manage_error(NULL, P_ERROR, NULL);
	return (fd);
}

static void	ft_file_not_empty(int fd)
{
	int		bytes_read;
	char	buffer[1];

	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read == -1)
		ft_manage_error(NULL, P_ERROR, NULL);
	if (bytes_read == 0)
		ft_manage_error("The map provided is empty.", U_ERROR, NULL);
}

static void	ft_check_content(int fd)
{
	char	*line;
	char	**line_content;
	size_t	line_len;
	size_t	next_line_len;

	next_line_len = 0;
	line_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_content = ft_split(line, ' ');
		if (line_content == NULL)
			ft_clean_exit(fd, NULL, P_ERROR);
		if (line_len == 0)
			line_len = ft_tablen(line_content);
		next_line_len = ft_tablen(line_content);
		ft_free_tab((void **)line_content);
		free(line);
		if (line_len != next_line_len)
			ft_clean_exit(fd, "Map format incorrect.", U_ERROR);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	ft_clean_exit(int fd, char *e_error, unsigned int e_type)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_manage_error(e_error, e_type, NULL);
}
