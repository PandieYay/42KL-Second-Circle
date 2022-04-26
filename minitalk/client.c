/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:40:39 by edlim             #+#    #+#             */
/*   Updated: 2022/04/26 14:40:40 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *useless)
{
	(void)sig;
	(void)useless;
	ft_putstr("Message has been sent at server: ");
	ft_putnbr(info->si_pid);
	write(1, "\n", 1);
}

static void	sendbits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		c = c >> 1;
		i++;
	}
}

static void	sendstr(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		sendbits(pid, str[i]);
		i++;
	}
	sendbits(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	sendstr(pid, argv[2]);
}
