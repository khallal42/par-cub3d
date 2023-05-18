/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:01:18 by khallal           #+#    #+#             */
/*   Updated: 2023/05/18 13:04:32 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int norm2(char **map)
{
    int     i;
    size_t  len;

    i = 0;
    len = ft_strlen(map[i]);
    while(map[i + 1])
    {
        if(len < ft_strlen(map[i + 1]))
            len = ft_strlen(map[i + 1]);
        i++;
    }
    return (len);
}

void    read_map(int fd, t_cub  *par)
{
    char    *k;
    char    **map;
    int     i;
    size_t len;

    k = get_next_line(fd);
    if(k[0] == '\0')
		(write(2, "Error\n", 7), exit(1));
    i = norm1(par, k);
    check_map(k, i);
    map = ft_split(&k[i], '\n');
    ft_check(map);
    len = norm2(map);
    map = ft_joinmap(map, len);
    ft_check_zero(map);
    par->map = ft_split(&k[i], '\n');
}