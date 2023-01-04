/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabail <saabail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:45:25 by saabail           #+#    #+#             */
/*   Updated: 2023/01/04 13:45:02 by saabail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s1, char **s2)
{
	if (s1)
		free(s1);
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup_nl(char *s1)
{
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (ft_free(0, &s1));
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		if (s2[i++] == '\n')
			break ;
	}
	s2[i] = '\0';
	return (s2);
}

void	*ft_memset(void *b, int c, int len)
{
	int		i;
	char	*char_b;

	char_b = (char *) b;
	if (len < 1)
		return (b);
	i = 0;
	while (i < len)
	{
		char_b[i] = c;
		i++;
	}
	return (b);
}
