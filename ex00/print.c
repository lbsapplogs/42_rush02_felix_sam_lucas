/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:50:45 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/27 18:50:47 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

/* Construit la cle d'un nombre entre 0 et 99. */
void	make_small_key(int nb, char *key)
{
	if (nb < 10)
	{
		key[0] = nb + '0';
		key[1] = '\0';
	}
	else
	{
		key[0] = nb / 10 + '0';
		key[1] = nb % 10 + '0';
		key[2] = '\0';
	}
}

/* Affiche un nombre entre 0 et 19. */
int	print_small(t_dict *dict, int nb, int count)
{
	char	key[3];

	make_small_key(nb, key);
	return (print_value(dict_find(dict, count, key)));
}

/* Affiche une dizaine et son unite si necessaire. */
int	print_tens(t_dict *dict, int nb, int count)
{
	char	key[3];

	key[0] = nb / 10 + '0';
	key[1] = '0';
	key[2] = '\0';
	if (!print_value(dict_find(dict, count, key)))
		return (0);
	if (nb % 10)
	{
		write(1, " ", 1);
		make_small_key(nb % 10, key);
		if (!print_value(dict_find(dict, count, key)))
			return (0);
	}
	return (1);
}

/* Choisit la methode d'affichage pour un nombre inferieur a 100. */
int	print_100(t_dict *dict, int nb, int count)
{
	if (nb < 20)
		return (print_small(dict, nb, count));
	return (print_tens(dict, nb, count));
}

/* Affiche une valeur du dictionnaire sans son retour a la ligne. */
int	print_value(char *val)
{
	int	i;

	if (!val)
		return (0);
	i = 0;
	while (val[i] && val[i] != '\n')
	{
		write(1, &val[i], 1);
		i++;
	}
	return (1);
}
