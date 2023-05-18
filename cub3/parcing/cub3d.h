#ifndef CUB3D_H
# define CUB3D_H


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cub
{
    char    **map;
    int     i;
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    int     f;
    int     c;
    int     d_f_c;
    int     fd;
    int     n;
    int     s;
    int     w;
    int     e;
}   t_cub;

char	*get_next_line(int fd);
void    read_map(int fd, t_cub *par);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
int	ft_atoi(char *s);
char	*ft_strtrim(char *s1, char *set);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    *cut(char *k);
void    check_ver(char *tmp);
int	ft_isdigit(char *c);
void    check_valu(char **f);
int    check_direction(char *tmp, t_cub *par, int i);
int check_direction1(char *tmp, t_cub *par, int i);
int check_floor(char *tmp, t_cub *par);
int check_celing(char *tmp, t_cub *par);
void text(char  *tmp, t_cub  *par);
int ft_check1(char **map);
void    ft_check(char **map);
void    check_map(char *k, int i);
char    *add_char(char *k, int len);
char    **ft_joinmap(char **map, int len);
void    ft_check_zero(char **map);
int norm1(t_cub *par, char *k);

#endif