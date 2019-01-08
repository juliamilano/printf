#include "ft_printf.h"

long long int cntdig(long long int n)
{
	long long int		cnt;
	long long int		i;

	i = 0;
	cnt = n;
	while (cnt != 0)
	{
		cnt /= 10;
		i++;
	}
	return (i);
}

static char		*negative(long long int n, long long int cnt)
{
	char	            *a;
	long long int		i;

	i = cnt;
	if (n < 0)
	{
		n *= -1;
		a = (char*)malloc(sizeof(char) * (cnt + 2));
		if (!a)
			return (NULL);
		while (i >= 0)
		{
			a[i--] = n % 10 + '0';
			n /= 10;
		}
		a[0] = '-';
		a[cnt + 1] = '\0';
		return (a);
	}
	return (NULL);
}

static char		*positive(long long int n, long long int cnt)
{
	char	            *a;
	long long int		i;

	i = cnt - 1;
	if (n > 0)
	{
		a = (char*)malloc(sizeof(char) * (cnt + 1));
		if (!a)
			return (NULL);
		while (i >= 0)
		{
			a[i--] = n % 10 + '0';
			n /= 10;
		}
		a[cnt] = '\0';
		return (a);
	}
	return (NULL);
}

char			*ft_litoa(long long int n)
{
	char	            *arr;
	long long int		cnt;


	cnt = cntdig(n);
	if (n < 0)
		arr = negative(n, cnt);
	else if (n > 0)
		arr = positive(n, cnt);
	else
	{
		arr = (char*)malloc(sizeof(char) * (2));
		if (!arr)
			return (NULL);
		arr[0] = '0';
		arr[1] = '\0';
	}
	if (!arr)
		return (NULL);
	return (arr);
}

char	*ft_itoa_li(long int value, int base)
{
	char		*s;
	long int	n;
	int			sign;
	int			i;

	n = (value < 0) ? -(long int)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
char	*ft_itoa_uli(unsigned long int value, int base)
{
	char				*s;
	unsigned long int	n;
	int					sign;
	int					i;

	n = value;
	sign = 0;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char	*ft_itoa_lli(long long int value, int base)
{
	char		*s;
	long long int	n;
	int			sign;
	int			i;

	n = (value < 0) ? -(long long int)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long long int)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char	*ft_itoa_ulli(unsigned long long int value, int base)
{
	char					*s;
	unsigned long long int 	n;
	int						sign;
	int						i;

	n = value;
	sign = 0;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}