/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:31:00 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/05 16:52:55 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*p;
	char		*tmp;
	char		*s;
	size_t		i;
	size_t		l;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	s = NULL;
	p = readline(fd, p);
	tmp = p;
	if (p != NULL)
	{
		l = ft_strlen(p, '\n');
		i = ft_strlen(p, '\0');
		s = ft_substr(p, 0, l + 1);
		p = ft_substr(p, l + 1, i - l);
	}
	free(tmp);
	return (s);
}

// int	main(void)
// {
// 	char	*p;
// 	int		fd;
// 	int		i;

// 	i = 1;
// 	fd = open("file.txt", O_RDWR, 0777);
// 	p = get_next_line(fd);
// 	while (p)
// 	{
// 		printf("%d-->|%s|", i++, p);
// 		free(p);
// 		p = get_next_line(fd);
// 	}
// 	printf("%d-->|%s|", i++, p);
// 	printf("\n");
// 	free(p);
// 	system("leaks a.out");
// }
