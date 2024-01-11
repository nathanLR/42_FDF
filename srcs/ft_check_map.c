/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:46 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/11 17:35:16 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static void	ft_free_tab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (*tmp)
		free(*tmp++);
	free(tab);
}

static bool	ft_parse(int fd)
{
	char	*line;
	char	**line_split;
	int		line_length;
	int		next_line_length;

	line_length = 0;
	next_line_length = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_split = ft_split(line, ' ');
		if (line_split == NULL)
		{
			ft_putstr_fd("Something went wrong with the parsing, exited.", STDERR_FILENO);
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line_length == 0)
			line_length = ft_tablen((const char **)line_split);
		next_line_length = ft_tablen((const char **)line_split);
		ft_free_tab(line_split);
		free(line);
		if (next_line_length != line_length)
			return (FALSE);
	}
	return (TRUE);
}

static int	ft_check_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (-1);
	}
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
	{
		perror("Error");
		close(fd);
		return (-1);
	}
	if (bytes_read == 0)
	{
		ft_putstr_fd("The map is empty, please choose another one.\n", STDERR_FILENO);
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (-1);
	}
	return (fd);
}

bool	ft_check_map(char *filename)
{
	int	fd;

	fd = ft_check_file(filename);
	if (fd == -1)
		return (FALSE);
	if (ft_parse(fd) == FALSE)
	{
		close(fd);
		errno = EMEDIUMTYPE;
		perror("Error");
		ft_printf("The map \"%s\" is incorrectly formatted\n", filename);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
