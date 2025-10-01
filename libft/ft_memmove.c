/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:28:04 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/30 18:34:09 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((unsigned char *)src < (const unsigned char *)dest)
	{
		d = (unsigned char *)dest + (n - 1);
		s = (const unsigned char *)src + (n - 1);
		while (n > 0)
		{
			*d-- = *s--;
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
