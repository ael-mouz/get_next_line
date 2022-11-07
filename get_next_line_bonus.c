/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:12:44 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/07 18:21:23 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*readline(int fd, char *p)
{
	char	*m;
	ssize_t	j;

	m = (char *)malloc(BUFFER_SIZE + 1);
	if (!m)
		return (free(p), NULL);
	while (ft_strchr(p, '\n') == NULL)
	{
		j = read(fd, m, BUFFER_SIZE);
		if (j < 0)
			return (free(m), free(p), NULL);
		m[j] = '\0';
		p = ft_strjoin(p, m);
		if (!p)
			return (free(m), NULL);
		if (j == 0 && p[0] == '\0')
			return (free(m), free(p), NULL);
		else if (j == 0)
			return (free(m), p);
	}
	free(m);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p[OPEN_MAX];
	char		*tmp;
	char		*s;
	size_t		i;
	size_t		l;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	s = NULL;
	p[fd] = readline(fd, p[fd]);
	if (!p[fd])
		return (NULL);
	tmp = p[fd];
	l = ft_strlen(p[fd], '\n');
	i = ft_strlen(p[fd], '\0');
	s = ft_substr(p[fd], 0, l + 1);
	p[fd] = ft_substr(p[fd], l + 1, i - l);
	free(tmp);
	return (s);
}
