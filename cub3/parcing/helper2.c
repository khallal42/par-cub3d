/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:43:28 by khallal           #+#    #+#             */
/*   Updated: 2023/05/16 18:09:40 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_floor(char *tmp, t_cub *par)
{
    int i;
    char **f;

    if(ft_strncmp(tmp, "F ", 2) == 0)
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
        par->d_f_c++;
        par->i++;
        return (1);
    }
    return (0);
}

int check_celing(char *tmp, t_cub *par)
{
    int     i;
    char    **f;

    if(ft_strncmp(tmp, "C ", 2) == 0)
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
        par->d_f_c++;
        par->i++;
        return (1);
	}
    return (0);
}

void text(char  *tmp, t_cub  *par)
{
    int i = 3;
    if(check_direction(tmp, par, i) || check_direction1(tmp, par, i))
        return ;
    if(check_floor(tmp, par) || check_celing(tmp, par))
        return ;
    if (par->d_f_c < 6)
        (write(2, "Error\n not correct", 19),exit(1));
}

int ft_check1(char **map)
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
    return (i);
}

void    ft_check(char **map)
{
    int i;
    int j;

    i = ft_check1(map) - 1;
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