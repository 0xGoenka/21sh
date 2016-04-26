/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:54:36 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/23 16:51:39 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft/libft.h"

int		main()
{
	int fd;
	char *s;

	while (42)
	{
		fd = open("debug.txt", O_RDONLY);

		while (get_next_line(fd, &s))
		{
			ft_putendl(s);
		}
		close(fd);
		usleep(800);
	}
	return (0);
}
