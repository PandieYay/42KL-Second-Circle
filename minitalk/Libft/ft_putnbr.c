#include <unistd.h>

void	ft_putnbr(int n)
{
	int	truenumber;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2,", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		truenumber = n + 48;
		write(1, &truenumber, 1);
	}
}
