/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:34:00 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/13 22:39:42 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buff[i] != '\0')
		{
			if (list->buff[i] == '\n')
			{
				len++;
				return(len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}
