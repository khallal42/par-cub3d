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

#endif