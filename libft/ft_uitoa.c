#include "libft.h"

static int		ft_len(long long num)
{
	int len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	if (num == 0)
		len++;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char			*ft_uitoa(unsigned int n)
{
	int		length;
	char	*str;
	int		i;
	long long	num;

	num = n;
	length = ft_len(num);
	if (!(str = (char*)malloc(sizeof(char) * length + 1)))
		return (NULL);
	i = 0;
	if (num < 0)
	{
		str[i] = '-';
		num *= -1;
	}
	i = length - 1;
	if (num == 0)
		str[i] = '0';
	while (num > 0)
	{
		str[i--] = num % 10 + 48;
		num /= 10;
	}
	str[length] = '\0';
	return (str);
}