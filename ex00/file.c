/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:48:52 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/27 18:48:54 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/* Copie un bloc de caracteres dans une autre chaine. */
void	ft_copy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

/* Ajoute un bloc de caracteres a partir d'une position. */
void	ft_append(char *dest, char *src, int start, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[start + i] = src[i];
		i++;
	}
}

/* Agrandit le buffer et ajoute les nouvelles donnees. */
char	*append_buffer(char *buffer, char *tmp, int total, int n)
{
	char	*new_buffer;

	new_buffer = malloc(total + n + 1);
	if (!new_buffer)
		return (0);
	ft_copy(new_buffer, buffer, total);
	ft_append(new_buffer, tmp, total, n);
	new_buffer[total + n] = '\0';
	free(buffer);
	return (new_buffer);
}

/* Lit le fichier par blocs de 1024 caracteres. */
char	*read_file(int fd, char *buffer)
{
	int		n;
	int		total;
	char	tmp[1024];
	char	*new_buffer;

	total = 0;
	n = read(fd, tmp, 1024);
	while (n > 0)
	{
		new_buffer = append_buffer(buffer, tmp, total, n);
		if (!new_buffer)
			return (free(buffer), (char *)0);
		buffer = new_buffer;
		total += n;
		n = read(fd, tmp, 1024);
	}
	if (n < 0)
		return (free(buffer), (char *)0);
	return (buffer);
}

/* Ouvre le fichier et charge tout son contenu en memoire. */
char	*load_file(char *filename)
{
	int		fd;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = malloc(1);
	if (!buffer)
		return (close(fd), (char *)0);
	buffer[0] = '\0';
	buffer = read_file(fd, buffer);
	close(fd);
	return (buffer);
}
