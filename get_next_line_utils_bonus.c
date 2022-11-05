/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:11 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/05 16:51:48 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s, char v)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != v)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;
	int		glen;

	if (!s1)
		s1 = ft_strdup("");
	i = -1;
	j = -1;
	glen = ft_strlen(s1, '\0') + ft_strlen(s2, '\0');
	ptr = (char *)malloc(sizeof(char) * glen + 1);
	if (!ptr)
		return (NULL);
	while (i < glen && s1[++i] != '\0')
		ptr[i] = s1[i];
	while (i < glen && s2[++j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*pt;

	i = 0;
	len = ft_strlen(s1, '\0');
	pt = (char *)malloc(sizeof(char) * len + 1);
	if (!pt)
		return (NULL);
	while (i < len)
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s, '\0'))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start], '\0'))
		len = ft_strlen(&s[start], '\0');
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (s[start] != '\0' && i < len && start <= ft_strlen(s, '\0'))
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
