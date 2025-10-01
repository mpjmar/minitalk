/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:15:40 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/30 18:14:48 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_pf(unsigned long n, unsigned long base, char c)
{
	char	*symbols_low;
	char	*symbols_upp;
	int		count;

	symbols_low = "0123456789abcdef";
	symbols_upp = "0123456789ABCDEF";
	count = 0;
	if (n < base && c == 'X')
	{
		write(1, &symbols_upp[n], 1);
		return (1);
	}
	else if (n < base)
	{
		write(1, &symbols_low[n], 1);
		return (1);
	}
	else
	{
		count = ft_putunbr_pf(n / base, base, c);
		return (count + ft_putunbr_pf(n % base, base, c));
	}
	return (count);
}
