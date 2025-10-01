/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:07:40 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/02 17:40:13 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	read_until_new_line(char *storage)
{
	ssize_t	size;
	ssize_t	len;

	size = 0;
	len = ft_strlen(storage);
	while (size < len && storage[size] != '\n' && storage[size] != '\0')
		size++;
	if (storage[size] == '\n')
		return (size + 1);
	return (size);
}

static int	is_a_new_line(char	*buffer, ssize_t bytes_read)
{
	ssize_t	pos;

	pos = 0;
	if (!buffer)
		return (0);
	while (pos < bytes_read)
	{
		if (buffer[pos] == '\n')
			return (1);
		pos++;
	}
	if (bytes_read == 0)
		return (1);
	return (0);
}

static char	*build_line(char *storage)
{
	char	*new_line;
	ssize_t	size;
	ssize_t	i;

	new_line = NULL;
	i = 0;
	size = read_until_new_line(storage);
	if (size == 0)
		return (NULL);
	new_line = ft_calloc_gnl((size + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	while (i < size)
	{
		new_line[i] = storage[i];
		i++;
	}
	return (new_line);
}

static char	*extract_backup(char *storage)
{
	ssize_t	size_backup;
	ssize_t	line_size;
	char	*backup;

	line_size = read_until_new_line(storage);
	size_backup = ft_strlen(storage) - line_size;
	backup = ft_substr_gnl(storage, line_size, size_backup);
	free(storage);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*new_line;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !is_a_new_line(buffer, bytes_read))
	{
		free(buffer);
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_clean(&buffer), ft_clean(&storage), NULL);
		storage = ft_strjoin_gnl(storage, buffer);
	}
	new_line = build_line(storage);
	storage = extract_backup(storage);
	free(buffer);
	return (new_line);
}
