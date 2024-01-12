/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:21:12 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/12 19:11:19 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fdf.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void	ft_manage_error(char *e_message, unsigned int e_type, t_data *destroy)
{
	if (destroy != NULL)
		ft_destroy_data(destroy);
	if (e_type == U_ERROR)
		ft_putendl_fd(e_message, STDERR_FILENO);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
