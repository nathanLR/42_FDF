/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:05:32 by nle-roux          #+#    #+#             */
/*   Updated: 2023/12/11 11:06:08 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}