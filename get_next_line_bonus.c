/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:55:41 by arepsa            #+#    #+#             */
/*   Updated: 2023/05/18 14:55:49 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*trim_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!remainder)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}

static char	*trim_new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_full_line(int fd, char *str)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

/*	FOPEN_MAX defines minimum nbr of files that can be open 
*	at the same time.
*	To see user limit: {ulimit -n} in terminal, or hardcoded {ulimit -n -H}
*	Pass static string with an fd index */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	str[fd] = get_full_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = trim_new_line(str[fd]);
	str[fd] = trim_remainder(str[fd]);
	return (line);
}
/*
int	main()
{
int		fd;
int		fd2;
int		i;
char	*line;
char	*file = "tests/short_poem";
char	*file2 = "tests/text_lines";

fd = open(file,  O_RDONLY);
fd2 = open(file2, O_RDONLY);
if (fd == -1)
{
	printf("Error opening file.\n");
	return (1);
}
i = 1;
while (i < 10)
{
	line = get_next_line(fd);
	printf("Line%d: %s\n", i, line);
	free(line);
	line = get_next_line(fd2);
	printf("Line%d: %s\n", i+1, line);
	free(line);
	i++;
}
close(fd);
close(fd2);
return (0);
}*/
