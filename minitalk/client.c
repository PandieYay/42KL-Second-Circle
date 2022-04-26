#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
}