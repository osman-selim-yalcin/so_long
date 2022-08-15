/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:09:14 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/08/13 16:49:46 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
int		ft_check(char *look, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, void *src, int n);
int		ft_strlen(char *s);
char	*print(char *k);
char	*newk(char *k);
char	*ft_strdup(char *s1);
#endif