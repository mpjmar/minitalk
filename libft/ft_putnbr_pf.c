/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:44:12 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/30 18:14:26 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_pf(int n, int base, char c)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	count = 0;
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	if (n < 0)
	{
		write (1, "-", 1);
		return (ft_putnbr_pf(-n, base, c) + 1);
	}
	else if (n < 10)
		return (write(1, &symbols[n], 1));
	else
	{
		count = ft_putnbr_pf(n / base, base, c);
		return (count + ft_putnbr_pf(n % base, base, c));
	}
	return (count);
}
