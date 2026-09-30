#include "rush02.h"
#include <stdlib.h>

/* Recupere et verifie la cle d'une ligne du dictionnaire. */
int	parse_key(char *line, t_dict *dict, int index)
{
	int		i;
	char	*key;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	dict[index].key = ft_strdup_range(line, 0, i);
	if (!dict[index].key)
		return (0);
	key = normalize_key(dict[index].key);
	free(dict[index].key);
	dict[index].key = key;
	if (!dict[index].key)
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] != ':')
	{
		free(dict[index].key);
		return (0);
	}
	return (i + 1);
}

/* Recupere et nettoie la valeur d'une ligne du dictionnaire. */
int	parse_value(char *line, t_dict *dict, int index, int start)
{
	int	end;

	while (line[start] == ' ')
		start++;
	end = start;
	while (line[end])
		end++;
	while (end > start && line[end - 1] == ' ')
		end--;
	if (end == start)
	{
		free(dict[index].key);
		return (0);
	}
	dict[index].value = ft_strdup_range(line, start, end);
	if (!dict[index].value)
	{
		free(dict[index].key);
		return (0);
	}
	return (1);
}

/* Parse une ligne complete du dictionnaire. */
int	parse_line(char *line, t_dict *dict, int index)
{
	int	start;

	start = parse_key(line, dict, index);
	if (!start)
		return (0);
	return (parse_value(line, dict, index, start));
}

/* Compte le nombre de lignes utiles du dictionnaire. */
int	count_lines(char *buffer)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buffer[i])
	{
		if ((i == 0 || buffer[i - 1] == '\n')
			&& buffer[i] != '\n')
			count++;
		i++;
	}
	return (count);
}