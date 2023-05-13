#include "cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (NULL);
	str = malloc(size * count);
	if (!(str))
		return (NULL);
	while (i < (size * count))
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	k = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(k))
		return (NULL);
	while (s1[i])
	{
		k[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		k[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	k[i] = '\0';
	return (k);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*khalifa;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	khalifa = malloc(sizeof(char) * (j + 1));
	if (!(khalifa))
		return (NULL);
	while (s1[i])
	{
		khalifa[i] = ((char *)s1)[i];
		i++;
	}
	khalifa[i] = '\0';
	return (khalifa);
}

char	*get_next_line(int fd)
{
	char	*h;
	char	*p;
	int		i;

	i = 1;
	h = ft_calloc(1,1);
	p = ft_calloc((BUFFER_SIZE + 1), 1);
	if (!p)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, p, BUFFER_SIZE);
		if (i == -1)
		{
			free(p);
			free(h);
			return (0);
		}
		p[i] = '\0';
		h = ft_strjoin(h, p);
	}
	free(p);
	return (h);
}
