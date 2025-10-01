/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:45:38 by maria-j2          #+#    #+#             */
/*   Updated: 2025/05/11 18:46:01 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*resul;
	unsigned int	i;

	i = 0;
	resul = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!resul || !s || !f)
		return (NULL);
	while (s[i])
	{
		resul[i] = (*f)(i, s[i]);
		i++;
	}
	resul[i] = '\0';
	return (resul);
}
