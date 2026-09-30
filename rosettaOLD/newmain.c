/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 14:48:26 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/26 20:33:41 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "dictionary.h"


int	validate(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!('0' <= argv[i] && argv[i] <= '9'))
			return(1);
		i++;
	}
	return (0);
}

long	ft_convert(char *argv)
{
	int	i;
	long	nombre;

	nombre = 0;
	i = 0;
	while (argv[i] != '\0')
	{
		nombre = nombre * 10 + argv[i] - '0';
		i++;
	}
	return (nombre);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_givemefreedom(struct s_dict *entries, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(entries[i].value);
		i++;
	}
	free(entries);
	return (NULL);
}

struct s_dict	*ft_file2struct(char **file)
{
	int					i;
	int					ac;
	struct s_dict	*dict;

	dict = malloc((/***ac***/ + 1) * sizeof(struct s_dict)); //What is ac for the dictionary?
	if (dict == NULL)
		ruturn (NULL);
	i = 0;
	while (i < ac)
	{
		dict[i].key = ;//
		dict[i].len = ft_strlen(file[i]);
		dict[i].value = ; //malloc((ft_strlen(av[i]) + 1) * sizeof(char));
		if (!dict[i].value)
			return (ft_givemefreedom(dict, i));
		i++;
	}
	dict[i].value = NULL;
	return (dict);
}

int	main(int argc, char **argv)
{
	// [PENDING] Comment faire un makefile
	// Qui : Felix
	long			nombre; // check type ?
	struct s_dict	**dict;
	


	if (!(argc == 2 || argc == 3))
		return(ft_error());

	//[DONE] Validate: positive number, only digits
	if (ft_validate(argv[argc - 1]) != 0)
		return(ft_error());
    //[DONE] Convert from string to long
	nombre = ft_convert(argv[argc - 1]);
    
	//[TODO] Load data from dictionary (open, read....)

	//[TODO] From dictionary to struct
	dict = ft_file2struct(/*file*/);

	//[TODO] Decomposer le nombre en cles du dictionaire
	//Receives: long
	//Return: ??
	
	
	// Qui: Sam 
	// Utiliser le cles pour parcourir le dictionaire - comment parcourir un dictionaire? 
	// Receives: ??
	// Return: ??

	// Qui: 


	return (0);
}