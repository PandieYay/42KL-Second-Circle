/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:54:05 by edlim             #+#    #+#             */
/*   Updated: 2022/04/07 11:54:06 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	nblen(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count++;
		count++;
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*convert(char *str, int n, int i)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

static char	*zero(char *str)
{
	str = malloc(sizeof(char) * (2));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = NULL;
	if (n == 0)
		return (zero(str));
	i = nblen(n) - 1;
	str = malloc(sizeof(char) * (nblen(n) + 1));
	if (!str)
		return (NULL);
	str[i + 1] = 0;
	return (convert(str, n, i));
}
