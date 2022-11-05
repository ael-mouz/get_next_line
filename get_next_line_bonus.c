/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:12:44 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/05 23:12:00 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*readline(int fd, char *p)
{
	char	*m;
	ssize_t	j;

	m = malloc(BUFFER_SIZE + 1);
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
		if (j == 0 && *(p) == '\0')
			return (free(m), free(p), NULL);
		else if (j == 0)
			return (free(m), p);
	}
	free(m);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p[10240];
	char		*tmp;
	char		*s;
	size_t		i;
	size_t		l;

	if (fd < 0 || fd > 102040 || BUFFER_SIZE <= 0)
		return (NULL);
	s = NULL;
	p[fd] = readline(fd, p[fd]);
	tmp = p[fd];
	if (p[fd] != NULL)
	{
		l = ft_strlen(p[fd], '\n');
		i = ft_strlen(p[fd], '\0');
		s = ft_substr(p[fd], 0, l + 1);
		p[fd] = ft_substr(p[fd], l + 1, i - l);
	}
	free(tmp);
	return (s);
}

int	main(void)
{
	char	*p;
	char	*p1;
	int		fd;
	int		fd1;

	fd = open("file.txt", O_RDWR, 0777);
	fd1 = open("file1.txt", O_RDWR, 0777);
	p = get_next_line(fd);
	p1 = get_next_line(fd1);
	printf("|%s|\n", p);
	printf("|%s|\n", p1);
	p = get_next_line(fd);
	p1 = get_next_line(fd1);
	printf("|%s|\n", p);
	printf("|%s|\n", p1);
	printf("\n");
	free(p);
	free(p1);
	// system("leaks a.out");
}
