/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabail <saabail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:05:51 by saabail           #+#    #+#             */
/*   Updated: 2023/01/04 17:24:45 by saabail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char static	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	if (!line)
		return (NULL);
	stash = ft_clean_stash(stash);
	if (!line || !stash)
		return (ft_free(line, &stash));
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (ft_free(buf, 0));
		stash[0] = '\0';
	}
	ft_memset(buf, '\0', BUFFER_SIZE + 1);
	readed = 1;
	while (!ft_find_nl(buf) && readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (ft_free(buf, &stash));
		buf[readed] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*ft_strjoin(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*concat;

	if (!stash || !buf)
		return (ft_free(buf, &stash));
	i = ft_strlen(stash);
	i += ft_strlen(buf);
	if (!i)
		return (ft_free(0, &stash));
	concat = malloc((i + 1) * sizeof(char));
	if (!concat)
		return (ft_free(0, &stash));
	i = -1;
	while (stash[++i])
		concat[i] = stash[i];
	j = 0;
	while (buf[j])
		concat[i++] = buf[j++];
	concat[i] = '\0';
	ft_free(0, &stash);
	return (concat);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (ft_free(0, &stash));
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	left = malloc(sizeof(char) * (ft_strlen(stash + i) + 1));
	if (!left)
		return (ft_free(0, &stash));
	j = 0;
	while (stash[i])
		left[j++] = stash[i++];
	left[j] = '\0';
	free(stash);
	return (left);
}
