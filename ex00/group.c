/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:49:06 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/27 18:49:08 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

/* Affiche un groupe de trois chiffres. */
int	print_group(t_dict *dict, int nb, int count)
{
	int		hundreds;
	int		rest;
	char	key[2];

	hundreds = nb / 100;
	rest = nb % 100;
	if (hundreds > 0)
	{
		key[0] = hundreds + '0';
		key[1] = '\0';
		if (!print_value(dict_find(dict, count, key)))
			return (0);
		write(1, " ", 1);
		if (!print_value(dict_find(dict, count, "100")))
			return (0);
	}
	if (rest > 0)
	{
		if (hundreds > 0)
			write(1, " ", 1);
		if (!print_100(dict, rest, count))
			return (0);
	}
	return (1);
}

/* Affiche un groupe et son unite de grandeur. */
int	print_part(t_dict *dict, char *group, int groups, int count)
{
	int		nb;
	char	scale[40];
	char	*val;

	nb = group_to_int(group);
	if (nb == 0)
		return (1);
	if (groups > 12)
		return (0);
	if (!print_group(dict, nb, count))
		return (0);
	if (groups > 0)
	{
		write(1, " ", 1);
		make_scale(groups, scale);
		val = dict_find(dict, count, scale);
		if (!print_value(val))
			return (0);
	}
	return (1);
}

/* Gere l'affichage d'un groupe non nul. */
int	print_group_part(t_dict *dict, char *group, int groups, int count)
{
	if (group_to_int(group) == 0)
		return (1);
	if (!print_part(dict, group, groups, count))
		return (0);
	return (1);
}

/* Parcourt le nombre groupe par groupe pour l'afficher. */
int	print_number_loop(t_dict *dict, char *number, int count, t_number *n)
{
	int		printed;
	char	group[4];

	printed = 0;
	while (n->pos < n->len)
	{
		get_group(number, n->pos, n->size, group);
		if (group_to_int(group) > 0)
		{
			if (printed)
				write(1, " ", 1);
			if (!print_group_part(dict, group, n->groups, count))
				return (0);
			printed = 1;
		}
		n->pos += n->size;
		n->size = 3;
		n->groups--;
	}
	return (1);
}

/* Traite les groupes successifs du nombre. */
int	print_number(t_dict *dict, char *number, int count)
{
	t_number	n;

	if (number[0] == '0' && number[1] == '\0')
		return (print_value(dict_find(dict, count, "0")));
	n.len = ft_strlen(number);
	n.first = first_group_len(number);
	n.pos = 0;
	n.groups = (n.len - n.first) / 3;
	n.size = n.first;
	return (print_number_loop(dict, number, count, &n));
}
