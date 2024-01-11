/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:05:26 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/11 17:35:53 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TRUE 1
# define FALSE 0
# define bool unsigned int
bool	ft_check_map(char *filename);
void	fdf(char *filename);
#endif
