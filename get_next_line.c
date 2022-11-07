/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:31:00 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/07 18:10:15 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*p;
	char		*tmp;
	char		*s;
	size_t		i;
	size_t		l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = NULL;
	p = readline(fd, p);
	if (!p)
		return (NULL);
	tmp = p;
	l = ft_strlen(p, '\n');
	i = ft_strlen(p, '\0');
	s = ft_substr(p, 0, l + 1);
	p = ft_substr(p, l + 1, i - l);
	free(tmp);
	return (s);
}
