/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:28:06 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/10 10:28:10 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_str(int fd, char *s_str)
{
	char	*buffer;
	ssize_t	len_resd;
	char	*temp;

	len_resd = 1;
	buffer = NULL;
	while (!ft_strchr(s_str, '\n') && len_resd != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		len_resd = read(fd, buffer, BUFFER_SIZE);
		if (len_resd == -1)
			return (free(buffer), NULL);
		buffer[len_resd] = '\0';
		if (len_resd == 0 && s_str == NULL)
			return (free(buffer), NULL);
		temp = s_str;
		s_str = ft_strjoin(s_str, buffer);
		free(temp);
		if (!s_str)
			return (free(buffer), NULL);
		free(buffer);
	}
	return (s_str);
}

char	*get_than_line(char *s_str)
{
	size_t	len;
	char	*buffer;

	len = 0;
	while (s_str[len] != 0 && s_str[len] != '\n')
		len++;
	buffer = malloc(sizeof(char) + (len + 2));
	if (!buffer)
		return (NULL);
	len = 0;
	while (s_str[len] != 0 && s_str[len] != '\n')
	{
		buffer[len] = s_str[len];
		len++;
	}
	if (s_str[len] == '\n')
	{
		buffer[len] = '\n';
		buffer[len + 1] = '\0';
	}
	else
		buffer[len] = '\0';
	return (buffer);
}

char	*get_remminder(char *s_str)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	len = 0;
	i = 0;
	while (s_str[len] != '\0' && s_str[len] != '\n')
		len++;
	if (s_str[len] == '\0')
		return (ft_strdup(""));
	buffer = malloc(sizeof(char) + ((ft_strlen(s_str) - len) + 1));
	if (!buffer)
		return (NULL);
	len++;
	while (s_str[len] != '\0')
	{
		buffer[i] = s_str[len];
		i++;
		len++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*s_str;
	char		*r_str;

	r_str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_str = get_read_str(fd, s_str);
	if (!s_str)
		return (NULL);
	r_str = get_than_line(s_str);
	if (!r_str)
		return (NULL);
	s_str = get_remminder(s_str);
	if (!s_str)
		return (free(r_str), NULL);
	if (s_str[0] == '\0')
	{
		free(s_str);
		s_str = NULL;
	}
	return (r_str);
}
