/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:40:07 by edlim             #+#    #+#             */
/*   Updated: 2022/04/10 15:40:07 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static void	check(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

static int	find_nl(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

static char	*read_file(char *buffer, char *str, int fd)
{
	int	text;

	text = 1;
	while (text > 0 && ft_strchr(str, '\n') == 0)
	{
		text = read(fd, buffer, BUFFER_SIZE);
		if (text == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[text] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

static char	*cutstr(char *str, int i)
{
	int		len;
	char	*temp;

	len = i;
	while (str[len] != 0)
		len++;
	temp = str;
	str = ft_substr(str, i, len);
	free (temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	int			i;
	static char	*str[1024];

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str[fd] = read_file(buffer, str[fd], fd);
	if (!str[fd])
		return (NULL);
	check(&buffer);
	i = 0;
	if (!str[fd][i])
	{
		check(&str[fd]);
		return (NULL);
	}
	i = find_nl(str[fd], i);
	line = ft_substr(str[fd], 0, i);
	str[fd] = cutstr(str[fd], i);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	get_next_line(fd);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }

// First I check if fd is invalid, then I malloc buffer wtih buffer size.
// Reason why not buffer[BUFFER_SIZE + 1] is because it cannot handle too
// much memory. Then I read the text file in read_file and store the read
// file inside str. I only read as much as BUFFER_SIZE allows me to and if 
// I find '\n' inside str I stop. After that, I check if str is null incase
// there was nothing to read. Then free buffer. I also check if the first
// of str[i] is null, if it is that means str has finished through entire file.
// Else, find_nl which just increments the index counter for str.
// Finally, I return the line in str between the start, and length between '\n'.
