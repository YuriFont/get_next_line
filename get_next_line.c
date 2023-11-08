/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:56:27 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/08 11:03:27 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_backup(int fd, char *backup)
{
	char	*buf;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = read(fd, buf, BUFFER_SIZE);
	backup = ft_strjoin(backup, buf);
	if (!backup)
		return (NULL);
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = add_backup(fd, backup);
}
