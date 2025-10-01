/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:15:38 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/25 18:25:40 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(const char *nptr)
{
	return ((*nptr >= 9 && *nptr <= 13) || *nptr == 32);
}

int	ft_atoi(const char *nptr)
{
	int	resul;
	int	sign;

	resul = 0;
	sign = 1;
	while (is_space(nptr))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit((int)*nptr))
	{
		resul = (resul * 10) + (*nptr - 48);
		nptr++;
	}
	if (resul >= 0)
		return (resul * sign);
	return (resul);
}
