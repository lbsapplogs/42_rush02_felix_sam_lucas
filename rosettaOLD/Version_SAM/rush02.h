#ifndef RUSH02_H
# define RUSH02_H

/* Représente une ligne du dictionnaire */
typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

/* Représente une requête complète du programme */
typedef struct s_request
{
	t_dict	*dict; //le dictionnaire chargé
	char	*number; //le nombre à convertir
	int		size; //le nombre d'entrée dans le dictionnaire
}	t_request;

/* Représente un nombre à afficher */
typedef struct s_number
{
	int	len;
	int	first;
	int	pos;
	int	groups;
	int	size;
}	t_number;

typedef struct s_load
{
	char	*buffer;
	t_dict	*dict;
	int		start;
	int		index;
}	t_load;

/* utils.c */
int		ft_strlen(char *str);
int		compare_key(char *a, char *b);
char	*ft_strdup(char *src);
char	*ft_strdup_range(char *str, int start, int end);
char	*normalize_key(char *key);

/* dict.c */
char	*dict_find(t_dict *dict, int size, char *key);
void	free_dict(t_dict *dict, int size);

/* file.c */
void	ft_copy(char *dest, char *src, int size);
void	ft_append(char *dest, char *src, int start, int size);
char	*append_buffer(char *buffer, char *tmp, int total, int n);
char	*read_file(int fd, char *buffer);
char	*load_file(char *filename);

/* parser.c*/
int		parse_key(char *line, t_dict *dict, int index);
int		parse_value(char *line, t_dict *dict, int index, int start);
int		parse_line(char *line, t_dict *dict, int index);
int		count_lines(char *buffer);

/* load.c */
int	    load_line(t_load *load, int end);
t_dict	*load_dict(char *buffer, int *size);

/* number.c */
int		first_group_len(char *number);
void	get_group(char *number, int start, int len, char *group);
int		group_to_int(char *group);
void	make_scale(int groups, char *scale);

/* print.c */
void	make_small_key(int nb, char *key);
int	    print_small(t_dict *dict, int nb, int count);
int	    print_tens(t_dict *dict, int nb, int count);
int		print_100(t_dict *dict, int nb, int count);
int		print_value(char *val);


/* group.c */
int		print_group(t_dict *dict, int nb, int count);
int		print_part(t_dict *dict, char *group, int groups, int count);
int	    print_group_part(t_dict *dict, char *group, int groups, int count);
int	    print_number_loop(t_dict *dict, char *number, int count, t_number *n);
int		print_number(t_dict *dict, char *number, int count);

/* check.c */
int		check_digits(t_dict *dict, int size);
int		check_teens(t_dict *dict, int size);
int		check_tens(t_dict *dict, int size);
int		check_basic_keys(t_dict *dict, int size);
int		check_scale_keys(t_dict *dict, int size);

/* prepare.c */
int		check_required_keys(t_dict *dict, int size);
int		is_valid_number(char *str);
char	*prepare_number(char *number);
int		check_argc(int argc);

/* main.c */
t_dict	*prepare_dict(char *buffer, int *size);
int	    prepare_request(int argc, char **argv, t_request *request);

#endif