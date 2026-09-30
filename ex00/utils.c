/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:51:03 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/27 18:51:06 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

/* Retourne la longueur d'une chaine. */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* Compare deux cles du dictionnaire. */
int	compare_key(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] == '\0' && b[i] == '\0')
		return (1);
	return (0);
}

/* Duplique une chaine avec malloc. */
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Duplique une partie d'une chaine entre start et end. */
char	*ft_strdup_range(char *str, int start, int end)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (0);
	i = 0;
	while (start < end)
		dest[i++] = str[start++];
	dest[i] = '\0';
	return (dest);
}

/* Supprime les zeros inutiles au debut d'une cle. */
char	*normalize_key(char *key)
{
	int	i;

	i = 0;
	while (key[i] == '0' && key[i + 1])
		i++;
	return (ft_strdup(&key[i]));
}
