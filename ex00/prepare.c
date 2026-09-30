/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:50:31 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/27 18:50:33 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* Verifie que le dictionnaire contient toutes les cles necessaires. */
int	check_required_keys(t_dict *dict, int size)
{
	if (!check_basic_keys(dict, size))
		return (0);
	return (check_scale_keys(dict, size));
}

/* Verifie que la chaine contient uniquement des chiffres. */
int	is_valid_number(char *str)
{
	int	i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* Valide le nombre avant son traitement. */
char	*prepare_number(char *number)
{
	if (!is_valid_number(number))
		return (0);
	return (number);
}

/* Verifie le nombre d'arguments du programme. */
int	check_argc(int argc)
{
	if (argc != 2 && argc != 3)
		return (0);
	return (1);
}
