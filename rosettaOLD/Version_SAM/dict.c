#include "rush02.h"
#include <stdlib.h>

/* Recherche une cle dans le dictionnaire. */
char	*dict_find(t_dict *dict, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (compare_key(dict[i].key, key))
			return (dict[i].value);
		i++;
	}
	return (0);
}

/* Libere toutes les cles, valeurs et le dictionnaire. */
void	free_dict(t_dict *dict, int size)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}