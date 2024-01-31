/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:52:27 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/30 15:21:37 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static float	ft_rad(float a)
{
	return (a * M_PI / 180.0);
}

static void	ft_rotate_z(t_vec3d *i, t_vec3d *o)
{
	float	a;
	float	rad_a;

	a = -45.0f;
	rad_a = ft_rad(a);
	o->color = i->color;
	o->x = i->x * cosf(rad_a) + i->y * sinf(rad_a);
	o->y = i->x * -sinf(rad_a) + i->y * cosf(rad_a);
	o->z = i->z;
}

static void	ft_rotate_x(t_vec3d *i, t_vec3d *o)
{
	float	a;

	a = atanf(sqrtf(2));
	o->color = i->color;
	o->x = i->x;
	o->y = i->y * cosf(a) + i->z * sinf(a);
	o->z = i->y * -sinf(a) + i->z * cosf(a);
}

void	ft_project(t_vec3d *i, t_vec3d *o)
{
	t_vec3d output;
	
	ft_rotate_z(i, &output);
	ft_rotate_x(&output, o);
	o->x += 200;
	o->y += 200;
}
