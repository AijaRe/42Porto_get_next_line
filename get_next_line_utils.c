/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:56:10 by arepsa            #+#    #+#             */
/*   Updated: 2023/05/18 14:56:14 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char *str;
	int	i;
	
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	i = 0;
	if (str)
	{
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
	}
	return str;
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0' && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int	i;
	int	j;

	i = 0;
	j = 0;
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		len;
	int		i;

	len = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strzero(char *str)
{
	while (*str)
		*str++ = '\0';
}
