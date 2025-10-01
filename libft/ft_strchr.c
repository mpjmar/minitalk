/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:16:29 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/25 18:57:37 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s1;
	unsigned char	c1;

	s1 = (char *)s;
	c1 = (unsigned char)c;
	while (*s1)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	if (*s1 == c1)
		return (s1);
	return (NULL);
}
