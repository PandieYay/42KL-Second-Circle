#include "minitalk.h"
#include <stdio.h>

void handler(int sig)
{
    ft_putstr("I wont die!\n");
	ft_putnbr(sig);
}

int	main(void)
{
	int	pid;
	struct sigaction sa;
	sa.sa_handler = handler;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	sigaction(SIGUSR1, &sa, NULL);
	while(1);
}