/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:23:23 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/30 18:24:57 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;

	s1 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	ft_strlcpy(s1, s, ft_strlen(s) + 1);
	return (s1);
}
