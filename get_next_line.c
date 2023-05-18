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

char	*check_remainder(char *remainder, char **line)
{
	char	*ptr_n;

	ptr_n = NULL;
	if (remainder)
	{
		if ((ptr_n = ft_strchr(remainder, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++ptr_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strzero(remainder);
		}
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	return (ptr_n);free(buff);
char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	char		*ptr_n;
	static char	*remainder;
	int			bytes_read;
	char		*tmp;

	ptr_n = check_remainder(remainder, &line);
	while (!ptr_n && (bytes_read = read(fd, buff, BUFFER_SIZE + 1)))
	{
		buff[bytes_read] = '\0';
		if ((ptr_n = ft_strchr(buff, '\n')))
		{
			*ptr_n = '\0';
			remainder = ft_strdup(++ptr_n);
		}
		tmp = line;
		line = ft_strjoin(line, buff);
		free (tmp);
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
