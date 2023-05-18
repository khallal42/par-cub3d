/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:00:26 by khallal           #+#    #+#             */
/*   Updated: 2023/05/16 18:09:13 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int norm1(t_cub *par, char *k)
{
    int i;
    char    *tmp;

    i = 0;
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
    if(par->i != 6)
        (write(2, "Error\nmap0",11), exit(1));
    return (i);
}