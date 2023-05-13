#include "cub3d.h"

char    *cut(char *k)
{
    char    *tmp;
    int     i;

    i = 0;
    while(k[i] && k[i] != '\n')
        i++;
    tmp = malloc(sizeof(char) * i + 1);
    i = 0;
    while(k[i] && k[i] != '\n')
    {
        tmp[i] = k[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

void    check_ver(char *tmp)
{
	int	i;
	int	ver;

	i = 0;
	ver = 0;
	while(tmp[i])
	{
		if(tmp[i] == ',')
			ver++;
        i++;
	}
	if (ver != 2)
		exit(2);
}
int	ft_isdigit(char *c)
{
    int i;

    i = 0;
    while(c[i])
    {
	    if (c[i] < 48 || c[i] > 57)
		    return (0);
        i++;
    }
	return (1);
}

void    check_valu(char **f)
{
    if(ft_atoi(f[0]) < 0 || ft_atoi(f[0]) > 255 || ft_atoi(f[1]) < 0 || ft_atoi(f[1]) > 255 || ft_atoi(f[2]) < 0 || ft_atoi(f[2]) > 255)
        (write(2, "Error\nthe value of the floor or celing not correct", 51), exit(1));
}

// void    check_direction()
// {
//     if(ft_strncmp(tmp, "SO ", 3) == 0)
//     {
//         while(tmp[i] == ' ')
//             i++;
//         fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
//         if (fd == -1)
//             (write(2, "Error\nsouth not exist", 22), exit(1));
//         par->SO = get_next_line(fd);
//         j++;
//         par->i++;
//     }
//     else if(ft_strncmp(tmp, "NO ", 3) == 0)
//     {
//         while(tmp[i] == ' ')
//             i++;
//         fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
//         if (fd == -1)
//             (write(2, "Error\nnorth not exist", 22), exit(1));
//         par->NO = get_next_line(fd);
//         j++;
//         par->i++;
//     }
// }

void text(char  *tmp, t_cub  *par)
{
    int i = 3;
	char	**f;
    int fd;
    static int j;
    if(ft_strncmp(tmp, "SO ", 3) == 0)
    {
        while(tmp[i] == ' ')
            i++;
        fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (fd == -1)
            (write(2, "Error\nsouth not exist", 22), exit(1));
        par->SO = get_next_line(fd);
        j++;
        par->i++;
    }
    else if(ft_strncmp(tmp, "NO ", 3) == 0)
    {
        while(tmp[i] == ' ')
            i++;
        fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (fd == -1)
            (write(2, "Error\nnorth not exist", 22), exit(1));
        par->NO = get_next_line(fd);
        j++;
        par->i++;
    }
    else if(ft_strncmp(tmp, "WE ", 3) == 0)
    {
        while(tmp[i] == ' ')
            i++;
        fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (fd == -1)
            (write(2, "Error\nwest not exist", 21), exit(1));
        par->WE = get_next_line(fd);
        j++;
        par->i++;
    }
    else if(ft_strncmp(tmp, "EA ", 3) == 0)
    {
        while(tmp[i] == ' ')
            i++;
        fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (fd == -1)
            (write(2, "Error\neast not exist", 21), exit(1));
        par->EA = get_next_line(fd);
        j++;
        par->i++;
    }
    else if(ft_strncmp(tmp, "F ", 2) == 0)
    {
        i = 2;
        check_ver(&tmp[i]);
		f = ft_split(ft_strtrim(&tmp[i], " "), ',');
        if(!f[0] || !f[1] || !f[2])
            (write(2, "Error\nthe floor not correct", 28),exit(1));
        if (!ft_isdigit(f[0]) || !ft_isdigit(f[1]) || !ft_isdigit(f[2]))
            (write(2, "Error\nthe floor not correct", 28),exit(1));
        check_valu(f);
		par->f = (ft_atoi(f[0]) * 65536) + (ft_atoi(f[1]) * 256) + ft_atoi(f[2]);
        j++;
        par->i++;
    }
    else if(ft_strncmp(tmp, "C ", 2) == 0)
	{
        i = 2;
        check_ver(&tmp[i]);
		f = ft_split(ft_strtrim(&tmp[i], " "), ',');
        if(!f[0] || !f[1] || !f[2])
            (write(2, "Error\nthe ceiling not correct", 30),exit(1));
        if (!ft_isdigit(f[0]) || !ft_isdigit(f[1]) || !ft_isdigit(f[2]))
            (write(2, "Error\nthe ceiling not correct", 30),exit(1));
        check_valu(f);
		par->c = (ft_atoi(f[0]) * 65536) + (ft_atoi(f[1]) * 256) + ft_atoi(f[2]);
        j++;
        par->i++;
	}
    else if(j < 6)
        (write(2, "Error\n not correct", 19),exit(1));
}

void    ft_check(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i][j])
    {
        if(map[i][j] != '1' && map[i][j] != ' ')
            (write(2, "Error\nmap1",11), exit(1));
        j++;
    }
    while(map[i])
    {
        if(map[i][0] != '1' && map[i][0] != ' ')
            (write(2, "Error\nmap2",11), exit(1));
        i++;
    }
    i--;
    j = 0;
    while (map[i][j])
    {
        if(map[i][j] != '1' && map[i][j] != ' ')
            (write(2, "Error\nmap3",11), exit(1));
        j++;
    }
    while(i >= 0)
    {
        j = ft_strlen(map[i]) - 1;
        if(map[i][j] != '1' && map[i][j] != ' ')
            (write(2, "Error\nmap4",11), exit(1));
        i--;  
    }
}

void    check_map(char *k, int i)
{
    int player;

    player = 0;
    while(k[i])
    {
        if(k[i] == 'N' || k[i] == 'S' || k[i] == 'W' || k[i] == 'E')
        {
            if(player == 1)
                (write(2, "Error\nmore than player", 23), exit(1));
            player++;
        }
        if(k[i] != '1' && k[i] != '0' && k[i] != ' ' && k[i] != 'N' && k[i] != 'S' && k[i] != 'W' && k[i] != 'E' && k[i] != '\n')
            (write(2, "Error\nforeign letter", 21), exit(1));
        i++;
    }
}

char    *add_char(char *k, int len)
{
    char    *map;
    int     i;

    i = 0;
    map = malloc(sizeof(char) * len + 1);
    while (k[i])
    {
        map[i] = k[i];
        i++;
    }
    while (i < len)
    {
        map[i] = '*';
        i++;
    }
    map[i] = '\0';
    return (map);
}

char    **ft_joinmap(char **map, int len)
{
    int j;
    char *k;

    j = 0;;
    while(map[j])
    {
        k = ft_strdup(map[j]);
        free(map[j]);
        map[j] = add_char(k, len);
        free(k);
        j++;
    }
    return (map);
}

void    ft_check_zero(char **map)
{
    int i;
    size_t j;

    i = 1;
    while (map[i + 1])
    {
        j = 1;
        while (j < ft_strlen(map[i]) - 2 && map[i + 1][j + 1])
        {
            if (map[i][j] == '0')
            {
                if(map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i + 1][j] == '*' || map[i - 1][j] == '*' || map[i][j + 1] == '*' || map[i][j - 1] == '*')
                {
                    (write(2, "Error\nlmap mt9oba2", 18), exit(1));}
            }
            j++;
        }
        i++;
    }
}



void    read_map(int fd, t_cub  *par)
{
    char    *k;
    char    **map;
    char    *tmp;
    int i = 0;
    size_t len;

    k = get_next_line(fd);
    while(k[i])
    { 
        while (k[i] && (k[i] == ' ' || k[i] == '\t'))
            i++;
        
        tmp = cut(&k[i]);
        text(tmp, par);
        free(tmp);
        while(k[i] && k[i] != '\n')
            i++;
        while(k[i] && k[i] == '\n')
            i++;
       if (par->i == 6)
            break ;
    }
    check_map(k, i);
    map = ft_split(&k[i], '\n');
    ft_check(map);
    i = 0;
    len = ft_strlen(map[i]);
    while(map[i + 1])
    {
        if(len < ft_strlen(map[i + 1]))
            len = ft_strlen(map[i + 1]);
        i++;
    }
    map = ft_joinmap(map, len);
    ft_check_zero(map);
}