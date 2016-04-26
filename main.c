/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:33:17 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/23 15:42:11 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		main()
{
	t_line line;
	char c;

	line.lst = init();
	line.lenx = 0;
	line.posx = 0;
	def_term();
	ft_putstr("21sh $> ");
	while (1)
	{
		c = readline(&line);
		if (c == -1)
			break ;
	//	movecursor();
		if (c != -2)
		{
			add(&line, c);
			printlast(line.lst);
		}
	}
}

char	readline(t_line *line)
{
	char buf[7];

	ft_bzero(buf,7);
	read(0, buf, 6);
	if (arrow(buf, line))
		return (-2);
	/*ft_putnbr(buf[0]);
	ft_putchar(' ');
	ft_putnbr(buf[1]);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putnbr(buf[2]);
	ft_putchar(' ');*/
	return (printablekey(buf));
}

void	movecursor(void)
{
//	char *s;
	char *p;
//	char *c;

	p = tgetstr("cd", 0);


	//tputs(s,1 , outc);
	tputs(p,1 , outc);
	//tputs(c,1 , outc);
}
