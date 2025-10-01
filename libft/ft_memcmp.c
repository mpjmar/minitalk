/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:08:19 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/25 18:27:06 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s10;
	unsigned char	*s20;
	size_t			i;

	s10 = (unsigned char *)s1;
	s20 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s10[i] == s20[i] && i < n - 1)
		i++;
	return ((int)(s10[i] - s20[i]));
}
