/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:35:11 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/31 18:54:12 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char			*s;
	unsigned long	i;

	i = 0;
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}

char	*ft_clean(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *storage, char *buffer)
{
	char	*new_storage;
	size_t	len_storage;
	size_t	len_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_storage = ft_strlen(storage);
	len_buffer = ft_strlen(buffer);
	new_storage = ft_calloc((len_storage + len_buffer + 1), sizeof(char));
	if (!new_storage)
		return (NULL);
	while (storage && i < len_storage)
	{
		new_storage[i] = storage[i];
		i++;
	}
	while (buffer && j < len_buffer)
		new_storage[i++] = buffer[j++];
	if (storage)
		free(storage);
	return (new_storage);
}

char	*ft_substr_gnl(char *storage, ssize_t line_size, size_t backup_size)
{
	char			*backup;
	unsigned int	i;

	i = 0;
	if (!storage || backup_size == 0)
		return (NULL);
	if (line_size >= (ssize_t)ft_strlen(storage))
		backup_size = 0;
	else if (line_size + backup_size > ft_strlen(storage))
		backup_size = ft_strlen(storage) - line_size;
	backup = ft_calloc((backup_size + 1), sizeof(char));
	if (backup == NULL)
		return (NULL);
	while (i < backup_size && storage[line_size + i])
	{
		backup[i] = storage[line_size + i];
		i++;
	}
	return (backup);
}
