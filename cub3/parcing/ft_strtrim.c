#include "cub3d.h"

static int	ft_check(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	start(char *k, char *h)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (k[i] != '\0')
	{
		if (ft_check(h, k[i]) == 1)
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

static size_t	fin(char *k, char *h)
{
	size_t	i;
	size_t	fin;

	fin = 0;
	i = ft_strlen(k);
	while (i > 0)
	{
		if (ft_check(h, k[i]) == 1)
		{
			fin = i;
			break ;
		}
		i--;
	}
	return (fin);
}

char	*ft_strtrim(char *s1, char *set)
{
	unsigned int	i;

	i = 0;
	if (!set || !s1)
		return (NULL);
	if ((fin(s1, set) == 0))
		return (ft_strdup(""));
	return (ft_substr(s1, start(s1, set), (fin(s1, set) - start(s1, set) + 1)));
}
