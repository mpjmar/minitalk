/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:15:39 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/25 18:26:30 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;
	long	num;

	num = n;
	if (num > 0)
		size = 0;
	else
	{
		size = 1;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*resul;
	size_t	size;

	num = n;
	size = get_size(n);
	if (n < 0)
		num *= -1;
	resul = malloc((size + 1) * sizeof(char));
	if (!resul)
		return (NULL);
	resul[size] = '\0';
	size--;
	while (num > 0)
	{
		resul[size--] = num % 10 + '0';
		num /= 10;
	}
	if (size == 0 && resul[1] == '\0')
		resul[0] = '0';
	else if (size == 0 && resul[1])
		resul[0] = '-';
	return (resul);
}
