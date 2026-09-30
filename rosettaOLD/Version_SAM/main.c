#include "rush02.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/* Verifie et charge le dictionnaire en memoire. */
t_dict	*prepare_dict(char *buffer, int *size)
{
	t_dict	*dict;

	dict = load_dict(buffer, size);
	if (!dict)
		return (0);
	if (!check_required_keys(dict, *size))
	{
		free_dict(dict, *size);
		return (0);
	}
	return (dict);
}

/* Prepare le nombre et charge le dictionnaire choisi. */
int	prepare_request(int argc, char **argv, t_request *request)
{
	char	*buffer;
	char	*number;

	request->dict = 0;
	request->number = 0;
	if (!check_argc(argc))
		return (0);
	if (argc == 2)
		number = argv[1];
	else
		number = argv[2];
	request->number = prepare_number(number);
	if (!request->number)
		return (0);
	if (argc == 2)
		buffer = load_file("numbers.dict");
	else
		buffer = load_file(argv[1]);
	if (!buffer)
		return (1);
	request->dict = prepare_dict(buffer, &request->size);
	free(buffer);
	if (!request->dict)
		return (1);
	return (2);
}

/* Point d'entree du programme. */
int	main(int argc, char **argv)
{
	t_request	request;
    int result;

	result = prepare_request(argc, argv, &request);
	if (result == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (result == 1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (!print_number(request.dict, request.number, request.size))
	{
		free_dict(request.dict, request.size);
		write(1, "Dict Error\n", 11);
		return (1);
	}
	write(1, "\n", 1);
	free_dict(request.dict, request.size);
	return (0);
}