#include "cub3d.h"

void	check_arg(int a)
{
	if (a != 2)
	{
		write(2, "Error\nther are not enough arg", 29);
		exit(1);
	}
}

void	check_fd(int i)
{
	if (i == -1)
	{
		write(1, "Error\nmap not exit", 19);
		exit(0);
	}
}

int	check_map_name(char *p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	i--;
	if (i == 3 || p[i] != 'b' || p[i - 1] != 'u' || p[i - 2] != 'c'
		|| p[i - 3] != '.')
	{
		write(1, "Error\nname map not correct", 26);
		exit(0);
	}
	return (1);
}
void	init(t_cub *par)
{
	par->map = NULL;
	par->NO = NULL;
	par->SO = NULL;
	par->WE = NULL;
	par->EA = NULL;
	par->f = 0;
	par->c = 0;
	par->i = 0;
	par->d_f_c = 0;
	par->w = 0;
	par->e = 0;
	par->s = 0;
	par->n = 0;
}

int main(int ac, char **av)
{
    int fd;
	t_cub	*par;

	par = malloc(sizeof(t_cub));
	init(par);
    check_arg(ac);
    check_map_name(av[1]);
    fd = open(av[1], O_RDWR);
    check_fd(fd);
	read_map(fd, par);
}