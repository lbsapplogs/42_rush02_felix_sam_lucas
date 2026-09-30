#include "rush02.h"

/* Verifie la presence des chiffres de 0 a 9. */
int	check_digits(t_dict *dict, int size)
{
	char	key[2];
	int		i;

	i = 0;
	while (i < 10)
	{
		key[0] = i + '0';
		key[1] = '\0';
		if (!dict_find(dict, size, key))
			return (0);
		i++;
	}
	return (1);
}

/* Verifie la presence des nombres de 10 a 19. */
int	check_teens(t_dict *dict, int size)
{
	char	key[3];
	int		i;

	i = 10;
	while (i < 20)
	{
		key[0] = i / 10 + '0';
		key[1] = i % 10 + '0';
		key[2] = '\0';
		if (!dict_find(dict, size, key))
			return (0);
		i++;
	}
	return (1);
}

/* Verifie la presence des dizaines de 20 a 90. */
int	check_tens(t_dict *dict, int size)
{
	char	key[3];
	int		i;

	i = 2;
	while (i < 10)
	{
		key[0] = i + '0';
		key[1] = '0';
		key[2] = '\0';
		if (!dict_find(dict, size, key))
			return (0);
		i++;
	}
	return (1);
}

/* Verifie toutes les cles de base necessaires. */
int	check_basic_keys(t_dict *dict, int size)
{
	if (!check_digits(dict, size))
		return (0);
	if (!check_teens(dict, size))
		return (0);
	return (check_tens(dict, size));
}

/* Verifie la presence de 100 et des puissances de 1000. */
int	check_scale_keys(t_dict *dict, int size)
{
	char	scale[40];
	int		groups;

	if (!dict_find(dict, size, "100"))
		return (0);
	groups = 1;
	while (groups <= 12)
	{
		make_scale(groups, scale);
		if (!dict_find(dict, size, scale))
			return (0);
		groups++;
	}
	return (1);
}