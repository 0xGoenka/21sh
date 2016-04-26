/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:29:49 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/22 19:51:47 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void print(t_lst *line)
{
	if (!line)
		return ;
		ft_putchar(line->a);

	print(line->next);
}

void printlast(t_lst *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	ft_putchar(lst->a);
}


int		countlst(t_lst *lst)
{
	int i;

	i = 0;
	while (lst->i)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
