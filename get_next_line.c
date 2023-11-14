/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:47:42 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/13 22:33:46 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_node(t_list **list, char *buff)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buff = buff;
	new_node->next = NULL;
}

void	creat_list(t_list **list, int fd)
{
	int		count_read;
	char	*buff;

	while (!found_newtline(*list))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		count_read = read(fd, buff, BUFFER_SIZE);
		if (!count_read)
		{
			free(buff);
			return ;
		}
		buff[count_read] = '\0';
		put_node(list, buff);
	}
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(sizeof(char) * (str_len + 1));
	if (!next_line)
		return (NULL);
	copy_str_list(list, next_str);
	return (next_str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	creat_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
}
