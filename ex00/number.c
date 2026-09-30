/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:50:03 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/27 18:50:04 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* Retourne la taille du premier groupe de chiffres. */
int	first_group_len(char *number)
{
	int	len;

	len = ft_strlen(number) % 3;
	if (len == 0)
		return (3);
	return (len);
}

/* Extrait un groupe de chiffres du nombre. */
void	get_group(char *number, int start, int len, char *group)
{
	int	i;

	i = 0;
	while (i < len)
	{
		group[i] = number[start + i];
		i++;
	}
	group[i] = '\0';
}

/* Convertit un groupe de chiffres en entier. */
int	group_to_int(char *group)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (group[i])
	{
		nb = nb * 10 + group[i] - '0';
		i++;
	}
	return (nb);
}

/* Construit la cle correspondant a une puissance de 1000. */
void	make_scale(int groups, char *scale)
{
	int	i;

	scale[0] = '1';
	i = 1;
	while (i <= groups * 3)
	{
		scale[i] = '0';
		i++;
	}
	scale[i] = '\0';
}
