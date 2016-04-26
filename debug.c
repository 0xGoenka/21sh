/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:39:14 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/25 18:55:58 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "sh.h"

int		debugtofile(t_line *line, char *s)
{
	int fd;
	s = NULL;
	t_lst *lst;
	fd = open("debug.txt", O_WRONLY);
	if (fd == -1)
	{
		ft_putstr("Open error occured\n");
		return (0);
	}
	lst = line->lst;
	if (lst && lst->next)
		lst = lst->next;
	else
	{
		close(fd);
		return (1);
	}
	ft_putstr_fd("list next => ", fd);
	while (lst->next)
	{
		ft_putchar_fd(lst->a, fd);
		lst = lst->next;
	}
	ft_putchar_fd(lst->a, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("list prev => ", fd);
	while (lst->prev)
	{
		ft_putchar_fd(lst->a, fd);
		lst = lst->prev;
	}
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("posx ", fd);
	ft_putnbr_fd(line->posx, fd);
	ft_putstr_fd("   lenx   ", fd);
	ft_putnbr_fd(line->lenx, fd);
	ft_putstr_fd("\n" , fd);
	close(fd);
	return (1);
}
