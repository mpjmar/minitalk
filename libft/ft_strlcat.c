/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:03:32 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/25 18:57:58 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (*src && dst_len <= size - 1 && size > 0)
	{
		while (*src && i < size - 1)
		{
			dst[i] = *src;
			src++;
			i++;
		}
		dst[i] = '\0';
	}
	if (dst_len > size)
		dst_len = size;
	return (dst_len + src_len);
}
