/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:24:51 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/13 21:38:36 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	fd;
	int	char_read;
	char	buff[400000];

	fd = open("test.txt", O_RDONLY | O_CREAT);
	while ((char_read = read(fd, buff, 5)))
	{
		buff[char_read] = '\0';
		printf("%s\n", buff);
	}
	return (0);
}
