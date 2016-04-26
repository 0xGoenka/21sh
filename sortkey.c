/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:06:33 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/25 19:12:24 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			arrow(char *s, t_line *line)
{
	if (s[0] == 27 && s[1] == 91 && s[2] == 68 && line->posx)
	{
		cursorleft(line);
		return (1);
	}
	if (s[0] == 27 && s[1] == 91 && s[2] == 67 && line->lenx != line->posx)
	{
		cursorright(line);
		return (1);
	}
	if (s[0] == 127 && s[1] == 0)
	{
		delelem(line);
		printend(line);
		return (1);
	}
	return (0);
}
void cursorleft(t_line *line)
{
	tputs(tgetstr("le", 0) ,1 , outc); // left
	line->posx--;
	debugtofile(line, "key left");
}
void cursorright(t_line *line)
{
	tputs(tgetstr("nd", 0) ,1 , outc); // left
	line->posx++;
	debugtofile(line, "key right");
}
char		printablekey(char *s)
{
	if (s[1] == 0 && s[0] >= 32 && s[0] <= 126)
		return (s[0]);
	return (-2);
}
void 		printend(t_line *line)
{
	int i;
	int j;
	t_lst *begin;

	i = 0;
	j = 0;
	begin = line->lst;
	tputs(tgetstr("ce", 0), 0, outc);
	line->lst = line->lst->next;
	debugtofile(line, "");
	while (line->lst)
	{
		if (i >= line->posx)
		{
			ft_putchar(line->lst->a);
			j++;
		}
		line->lst = line->lst->next;
		i++;
	}
	while (j)
	{
		tputs(tgetstr("le", 0) ,1 , outc); // left
		j--;
	}

	line->lst = begin;
}
