#include "utils.h"

void	ft_putchar(char ch, int fd)
{
	write(fd, &ch, 1);
}

void	ft_putstr(char *src, int fd)
{
	int	iter;

	iter = 0;
	while (src[iter])
	{
		ft_putchar(src[iter], fd);
		iter++;
	}
}

void	ft_putnbr(int nbr, int fd)
{
	char	res;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2147483648", fd);
			return ;
		}
		ft_putchar('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, fd);
	res = nbr % 10 + '0';
	ft_putchar(res, fd);
}

char    *ft_strdup(const char *s)
{
    int     iter;
    int     len;
    char    *buff;

    iter = 0;
    len = ft_strlen(s);
    buff = malloc(sizeof(char *) * (len + 1));
    if(!buff)
        return NULL;
    while(s[iter] != '\0')
    {
        buff[iter] = s[iter];
        iter++;
    }
    buff[iter] = '\0';
    return(buff);
}

int     ft_strlen(const char *s)
{
    int     len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}