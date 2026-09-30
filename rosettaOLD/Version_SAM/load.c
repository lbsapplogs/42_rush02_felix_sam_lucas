#include "rush02.h"
#include <stdlib.h>

/* Parse une ligne et ajoute son entree au dictionnaire. */
int	load_line(t_load *load, int end)
{
	load->buffer[end] = '\0';
	if (!load->buffer[load->start])
		return (1);
	if (!parse_line(&load->buffer[load->start],
			load->dict, load->index))
		return (0);
	load->index++;
	load->start = end + 1;
	return (1);
}

/* Transforme le contenu du fichier en tableau de t_dict. */
t_dict	*load_dict(char *buffer, int *size)
{
	t_load	load;
	int		i;

	*size = count_lines(buffer);
	load.dict = malloc(sizeof(t_dict) * (*size));
	if (!load.dict)
		return (0);
	load.buffer = buffer;
	load.start = 0;
	load.index = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (!load_line(&load, i))
				return (free_dict(load.dict, load.index),
					(t_dict *)0);
		}
		i++;
	}
	if (buffer[load.start]
		&& !parse_line(&buffer[load.start], load.dict, load.index))
		return (free_dict(load.dict, load.index), (t_dict *)0);
	return (load.dict);
}
