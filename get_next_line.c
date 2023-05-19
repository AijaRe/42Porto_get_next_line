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

#include "get_next_line.h"

static char		*trim_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] == '\n')
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

static char 	*trim_new_line(char *str)
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
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*str;
	int			bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			//free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	if (str)
	{
		line = trim_new_line(str);
		str = trim_remainder(str);
	}
	return (line);
}

int	main()
{
int		fd;
int		i;
char	*line;
char	*file = "tests/text_lines.txt";

fd = open(file,  O_RDONLY);
if (fd == -1)
{
	printf("Error opening file.\n");
	return (1);
}
i = 1;
while (i < 7)
{
	line = get_next_line(fd);
	printf("Line%d: %s\n", i, line);
	free(line);
	i++;
}
close(fd);
return (0);
}
