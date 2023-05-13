

int	ft_atoi(char *s)
{
	long long int	res;
	int				sign;
	int				i;

	res = 0;
	i = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{	
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = res * 10 + s[i] - '0';
		if (res > 922337203775807 && sign == 1)
			return (-1);
		if (res > 922337203775807 && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}
