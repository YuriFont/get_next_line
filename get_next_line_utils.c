/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:19:03 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/09 18:43:31 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *backup, char *buf)
{
	int		i;
	int		j;
	char	*r;

	if (!backup)
	{
		backup = malloc(sizeof(char) * 1);
		backup[0] = '\0';
	}
	if (!buf || !backup)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(backup) + ft_strlen(buf) + 1));
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	if (backup)
		while (backup[i++] != '\0')
			r[i] = backup[i];
	while (buf[j] != '\0')
		r[i++] = buf[j++];
	r[ft_strlen(backup) + ft_strlen(buf)] = '\0';
	free(backup);
	return (r);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
