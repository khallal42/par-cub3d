#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	// if(!s1)
	// 	(write(2, "Error:", 7), exit(1));
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (i < n && (s3[i] != '\0' || s4[i] != '\0'))
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (0);
}
