/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:29:22 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/11 17:53:01 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "../MacroLibX/includes/mlx.h"

void	fdf(char *filename)
{
	(void)filename;
	void	*mlx;

	mlx = mlx_init();
	mlx_destroy_display(mlx);
}
