/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:33:28 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/25 18:26:01 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	delelem(t_line *line)
{
	int i;
	t_lst *after;
	t_lst *before;
	t_lst *begin;

	begin = line->lst;
	i = 0;
	if (line->posx == 0)
		return ;
	while (i < line->posx)
	{
		if (line->lst)
			line->lst = line->lst->next;
		i++;
	}
	/*if (line->posx == line->lenx)
	{
		line->lst = NULL;
		line->lst = begin;
		debugtofile(line , "delelem mid");
		return ;
	}*/
	after = line->lst->next;
 	before = line->lst->prev;
	if (after)
		after->prev = before;
	else
		after = NULL;
	before->next = after;
	line->lenx--;
	cursorleft(line);
	line->lst = begin;
	debugtofile(line , "");
}

void	fin(t_lst *lst)
{
	t_lst *begin;

	begin = lst;
	if (begin->next)
		begin->next->curse = 1;
	while (lst->next)
		lst = lst->next;
	lst->next = begin;
	begin->prev = lst;
}

void	add(t_line *line, char a)
{
	t_lst *tmp;
	t_lst *begin;

	begin = line->lst;
	while (line->lst->next)
		line->lst = line->lst->next;
	if (!(line->lst->next = malloc(sizeof(t_lst))))
		return ;
	tmp = line->lst;
	line->lst = line->lst->next;
	line->lst->next = NULL;
	line->lst->prev = tmp;
	line->lst->i = 1;
	line->lst->sel = 0;
	line->lst->curse = 0;
	line->lst->a = a;
	line->posx++;
	line->lenx++;
	line->lst = begin;
	debugtofile(line, "Add elem");
}

t_lst	*init(void)
{
	t_lst *lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->next = NULL;
	lst->prev = NULL;
	lst->a = 0;
	lst->sel = 0;
	lst->curse = 1;
	lst->i = 0;
	return (lst);
}

void	lstdel(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}
