/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:31:00 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/04 23:51:52 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *p)
{
	char	*m;
	ssize_t	j;

	m = malloc(BUFFER_SIZE + 1);
	while (ft_strchr(p, '\n') == NULL)
	{
		j = read(fd, m, BUFFER_SIZE);
		if (j < 0)
			return (free(m), free(p), NULL);
		m[j] = '\0';
		p = ft_strjoin(p, m);
		if (j == 0 && *p == '\0')
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
	if (p == NULL)
		p = ft_strdup("");
	p = readline(fd, p);
	tmp = p;
	if (p != NULL)
	{
		l = ft_strlen(p, '\n');
		i = ft_strlen(p, '\0');
		s = ft_substr(p, 0, l + 1);
	}
	if (p != NULL)
		p = ft_substr(p, l + 1, i - l + 1);
	free(tmp);
	return (s);
}

// int	main(void)
// {
// 	char	*p;
// 	int		fd;

// 	fd = open("file.txt", O_RDWR, 0777);
// 	p = get_next_line(fd);
// 	while (p)
// 	{
// 		printf("-->|%s|\n", p);
// 		free(p);
// 		p = get_next_line(fd);
// 	}
// 	free(p);
// 	system("leaks a.out");
// }
