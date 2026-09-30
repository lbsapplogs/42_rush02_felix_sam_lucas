#include <unistd.h>

int	parsing(int argc, char **argv, double nombre)
{
	int	i;
	int	a;

	if (argc == 2)
		a = 1;
	else if (argc == 3)
		a = 2;
	else
	{
		write(1, "Error\n", 6);
		return (- 1);
	}
	i = (- 1);
	while (i++, argv[a][i] != '\0')
	{
		if ('0' <= argv[a][i] && argv[a][i] <= '9')
			nombre = nombre * 10 + rgv[a][i] - '0';
		else
		{
			write(1, "Error\n", 6);
			return (- 1);
		}
	}
	return (nombre);
}

int	main(int argc, char **argv)
{
	double nombre;

	nombre = 0;
	nombre = parsing(argc, argv, nombre);
	if (nombre == (- 1))
		return (0);
	write(1, "test", 4);
	return (1);
}
