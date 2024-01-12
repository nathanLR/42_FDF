/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:54 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/12 18:18:42 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include <fdf.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_manage_error("Usage: ./fdf [path_to_file].fdf", U_ERROR, NULL);
	ft_check_map(argv[1]);
}
