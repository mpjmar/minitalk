/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:10:33 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/25 18:58:22 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*s1;

	s1 = (char *)s;
	len = ft_strlen(s1);
	while (len >= 0)
	{
		if (s1[len] == (char)c)
			return (s1 + len);
		len--;
	}
	return (NULL);
}
