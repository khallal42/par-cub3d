/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:41:54 by khallal           #+#    #+#             */
/*   Updated: 2023/05/16 18:18:18 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_isdigit(char *k)
{
    int i;
    char    *c;

    i = 0;
    c = ft_strtrim(k, " ");  
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

int    check_direction(char *tmp, t_cub *par, int i)
{
    if(ft_strncmp(tmp, "SO ", 3) == 0)
    {
        if(par->s == 1)
            (write(2, "Error\ndouble south", 19), exit(1));
        while(tmp[i] == ' ')
            i++;
        par->fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (par->fd == -1)
            (write(2, "Error\nsouth not exist", 22), exit(1));
        par->SO = get_next_line(par->fd);
        par->d_f_c++;
        par->i++;
        par->s++;
        return (1);
    }
    else if(ft_strncmp(tmp, "NO ", 3) == 0)
    {
        if(par->n == 1)
            (write(2, "Error\ndouble north", 19), exit(1));
        while(tmp[i] == ' ')
            i++;
        par->fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (par->fd == -1)
            (write(2, "Error\nnorth not exist", 22), exit(1));
        par->NO = get_next_line(par->fd);
        par->d_f_c++;
        par->i++;
        par->n++;
        return (1);
    }
    return (0);
}

int check_direction1(char *tmp, t_cub *par, int i)
{
    if(ft_strncmp(tmp, "WE ", 3) == 0)
    {
        if(par->w == 1)
            (write(2, "Error\ndouble west", 18), exit(1));
        while(tmp[i] == ' ')
            i++;
        par->fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (par->fd == -1)
            (write(2, "Error\nwest not exist", 21), exit(1));
        par->WE = get_next_line(par->fd);
        par->d_f_c++;
        par->i++;
        par->w++;
        return (1);
    }
    else if(ft_strncmp(tmp, "EA ", 3) == 0)
    {
        if(par->e == 1)
            (write(2, "Error\ndouble east", 18), exit(1));
        while(tmp[i] == ' ')
            i++;
        par->fd = open(ft_strtrim(&tmp[i], " "), O_RDONLY);
        if (par->fd == -1)
            (write(2, "Error\neast not exist", 21), exit(1));
        par->EA = get_next_line(par->fd);
        par->d_f_c++;
        par->i++;
        par->e++;
        return (1);
    }
    return (0);
}