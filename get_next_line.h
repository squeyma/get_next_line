/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabail <saabail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:31 by saabail           #+#    #+#             */
/*   Updated: 2023/01/04 13:31:58 by saabail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_free(char *s1, char **s2);
char	*ft_strjoin(char *stash, char *buf);
int		ft_strlen(char *s);
char	*ft_read(int fd, char *save);
void	*ft_memset(void *b, int c, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *s1);
char	*ft_clean_stash(char *stash);
int		ft_find_nl(char *str);
char	*ft_strdup_nl(char *s1);

#endif