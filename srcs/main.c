/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:54 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/11 17:36:18 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc - 1 != 1)
	{
		errno = EINVAL;
		perror("Error");
		ft_printf("Usage: ./fdf [path_to_map].fdf\n");
		exit(EXIT_FAILURE);
	}
	if (ft_check_map(argv[1]) == TRUE)
		fdf(argv[1]);
	else
		exit(EXIT_FAILURE);
	return (0);
}
