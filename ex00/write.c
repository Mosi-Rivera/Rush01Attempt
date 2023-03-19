#include<unistd.h>

void	put_error()
{
	write(1, "Error", 5);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


