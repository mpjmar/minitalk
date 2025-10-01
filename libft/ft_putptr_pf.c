/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:44:22 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/30 18:14:34 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_pf(void	*p, int base, char c)
{
	int	counter;

	if (!p)
		return (write(1, "(nil)", 5));
	counter = write(1, "0x", 2);
	counter += ft_putunbr_pf((unsigned long)p, base, c);
	return (counter);
}
