/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:51:31 by edlim             #+#    #+#             */
/*   Updated: 2022/04/06 17:29:43 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	seperator(char c, char charset)
{
	if (c == '\0')
		return (1);
	if (c == charset)
		return (1);
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	strs;

	i = 0;
	strs = 0;
	while (str[i] != 0)
	{
		if (seperator(str[i + 1], c) == 1
			&& seperator(str[i], c) == 0)
			strs++;
		i++;
	}
	return (strs);
}

static void	ft_strcpysplit(char *dest, char *src, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	splitit(char **dest, char const *str, char c)
{
	int		i;
	int		size;
	int		strs;

	strs = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (seperator(str[i], c) == 1)
			i++;
		else
		{
			size = 0;
			while (seperator(str[i + size], c) == 0)
				size++;
			dest[strs] = malloc(sizeof(char) * (size + 1));
			ft_strcpysplit(dest[strs], (char *)str + i, size);
			i += size;
			strs++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		strs;

	if (!s)
		return (NULL);
	strs = count_words(s, c);
	dest = malloc(sizeof(char *) * (strs + 1));
	if (!dest)
		return (NULL);
	splitit(dest, s, c);
	dest[strs] = 0;
	return (dest);
}
