#include "cub3d.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	j;
	char			*khalifa;

	i = 0;
	j = start;
	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	khalifa = malloc(sizeof(char) * len + 1);
	if (!(khalifa))
		return (NULL);
	while (j < (len + start))
	{
		khalifa[i] = s[j];
		i++;
		j++;
	}
	khalifa[i] = '\0';
	return (khalifa);
}
