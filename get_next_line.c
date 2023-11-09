/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:56:27 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/09 18:25:48 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(int fd, char *backup)
{
	char	*buf;
	int		n_rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(backup, '\n') && n_rd != 0)
	{
		n_rd = read(fd, buf, BUFFER_SIZE);
		if (n_rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[n_rd] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*r;

	i = 0;
	if (!backup)
		return (NULL);
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	r = malloc(sizeof(char) * (i + 2));
	if (!r)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
	{
		r[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		r[i] = '\n';
	r[i] = '\0';
	return (r);
}

char	*ft_reset_backup(char *backup)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	r = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!r)
	{
		free(backup);
		return (NULL);
	}
	i++;
	j = 0;
	while (backup[i] != '\0')
		r[j++] = backup[i++];
	r[j] = '\0';
	free(backup);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_next_line(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_reset_backup(backup);
	return (line);
}
