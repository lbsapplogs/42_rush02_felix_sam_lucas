#include <fcntl.h>
#include <unistd.h>

/*
void find_sep(char *str)
{
    int i;
    i = 0;
    while (str[i] != ':' && str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void find_val(char *str)
{
    int i;
    i = 0;
    while (str[i] != ':' && str[i] != '\0')
        i++;
    if (str[i] == ':')
        i++;
    while (str[i] == ' ')
        i++;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}
*/
void print_input(char *str)
{
    int i;

    i = 0;
    while (str[i] != ':' && str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, " -> ", 4);
    if (str[i] == ':')
        i++;
    while (str[i] == ' ')
        i++;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}
/*
int ft_cmpkey(char *row, char *nb, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (row[i] != nb[i])
            return (0);
        i++;
    }
    return (1);
}
*/
/* Compare une clé avec un nombre*/
int ft_cmpkey(char *key, char *nb)
{
    int i;

    i = 0;
    while (key[i] != '\0' && nb[i] != '\0')
    {
        if (key[i] != nb[i])
            return (0);
        i++;
    }
    return (key[i] == '\0' && nb[i] == '\0');
}
/*
char *ft_getval(char *row, char *nb)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(row[len] != ' ' && row[len] != ':')
        len++;
    if (ft_cmpkey(row, nb, len) == 0)
        return (NULL);
    i = 0;
    while (row[i] != ':')
        i++;
    i++;
    while (row[i] == ' ')
        i++;
    return (&row[i]);
}
*/
/* Récupère la valeur d'une ligne */
char *ft_getval(char *row, char *nb)
{
    int i;
    int start;
    int end;
    int j;

    i = 0;
    while(row[i] == ' ')
        i++;
    start = i;
    while (row[i] != ':' && row[i] != '\0')
        i++;
    if (row[i] == '\0')
        return (NULL);
    end = i - 1;
    while (end >= start && row[end] == ' ')
        end--;
    j = 0;
    while (start <= end && row[start] == nb[j])
    {
        start++;
        j++;
    }
    if (start <= end || nb[j] != '\0')
        return (NULL);
    i++;
    while (row[i] == ' ')
        i++;
    return (&row[i]);
}
/* Recherche une valeur dans toutes les lignes */
char *find_val(char **row, char *nb, int count)
{
    int i;
    char *val;

    i = 0;
    while (i < count)
    {
        val = ft_getval(row[i], nb);
        if (val != NULL)
            return (val);
        i++;
    }
    return (NULL);
}

/* Sépare le buffer en lignes*/
int ft_splitrow(char *buffer, char **row, int max_rows)
{
    int i;
    int count_row;

    i = 0;
    count_row = 0;
    while (buffer[i] != '\0')
    {
        while (buffer[i] == '\n')
            i++;
        if (buffer[i] == '\0')
            break;
        if (count_row >= max_rows)
            return (-1);
        row[count_row] = &buffer[i];
        count_row++;
        while (buffer[i] != '\0' && buffer[i] != '\n')
            i++;
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
            i++;
        }
    }
    return (count_row);
}

int ft_loaddict(char *dict, char *buffer, char **row)
{
    int fd;
    int bytes;
    int count;

    fd = open(dict, O_RDONLY);
    if (fd == -1)
        return (-1);
    bytes = read(fd, buffer, 4095);
    close(fd);
    if (bytes <= 0)
        return (-1);
    buffer[bytes] = '\0';
    count = ft_splitrow(buffer, row, 100);
    return (count);
}

void ft_printrow(char *val)
{
    int i;

    i = 0;
    while (val[i] != '\0' && val[i] != '\n')
        i++;
    write(1, val, i);
}

int ft_printnb(char **row, char *nb, int count)
{
    char diz[3];
    char unit[2];
    char *val1;
    char *val2;

    if (nb[0] == '\0')
        return (0);
    if (nb[1] == '\0')
    {
        val1 = find_val(row, nb, count);
        if (val1 == NULL)
            return (0);
        ft_printrow(val1);
        write(1, "\n", 1);
        return (1);
    }
    diz[0] = nb[0];
    diz[1] = '0';
    diz[2] = '\0';
    unit[0] = nb[1];
    unit[1] = '\0';
    val1 = find_val(row, diz, count);
    if (val1 == NULL)
        return (0);
    ft_printrow(val1);
    if (unit[0] != '0')
    {
        val2 = find_val(row, unit, count);
        if (val2 == NULL)
            return (0);
        write(1, " ", 1);
        ft_printrow(val2);
    }
    write(1, "\n", 1);
    return (1);
}

int main()
{
    /*
    int fd;
    int bytes;
    int i;
    char c;
    char row[1024];
    
    fd = open("numbers.dict", O_RDONLY);
    if (fd == -1)
        return (write(2, "Dict Error\n", 11), 1);
    i = 0;
        bytes = read(fd, &c, 1);
    while (bytes > 0)
    {
        if (c == '\n')
        {
            row[i] = '\0';
            print_input(row);
            i = 0;
        }
        else if (i < 1023)
            row[i++] = c;
        else
        {
            close(fd);
            return (write(2, "Dict Error\n", 11), 1);
        }
        bytes = read(fd, &c, 1);
    }
    if (i > 0)
    {
        row[i] = '\0';
        print_input(row);
    }
    close(fd);
    */
    char buffer[4096];
    char *row[100];
    //char *val;
    int count;
    //int i;
    //int j;
    count = ft_loaddict("numbers.dict", buffer, row);
    /*
    if (count == -1)
        return (1);
    */
    if (count == -1)
    {
        write(2, "Dict Error\n", 11);
        return (1);
    }
    write(1, "Dict loaded successfully\n", 26);
    /*
    i = 0;
    while (i < count)
    {
        j = 0;
        while(row[i][j] != '\0')
            j++;
        write(1, row[i], j);
        write(1, "\n", 1);
        i++;
    }
    val = find_val(row, "10", count);
    if (val == NULL)
        write(2, "Value not found\n", 16);
    else
    {
        write(1, "Value found\n", 12);
        i = 0;
        while (val[i] != '\0' && val[i] != '\n')
            i++;
        write(1, val, i);
        write(1, "\n", 1);
    }
    */
    if (ft_printnb(row, "42", count) == 0)
    {
        write(2, "Value not found\n", 16);
        return (1);
    }
    return (0);
}