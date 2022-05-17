/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoichecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:22:38 by edlim             #+#    #+#             */
/*   Updated: 2022/05/17 17:48:33 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_atoichecker(const char *str)
{
	long	nb;
	int		minusi;
	int		i;

	nb = 0;
	minusi = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		minusi = -minusi;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (nb > 2147483647)
		return ('K');
	return ('O');
}
