/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:32:23 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/25 17:54:48 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h> //sdd
# include <termcap.h>
# include <termios.h>
# include <curses.h>

typedef struct					s_lst
{
		char					a;
		bool					curse;
		bool					sel;
		bool					i;
		struct s_lst			*next;
		struct s_lst			*prev;
}								t_lst;

typedef struct 		s_line
{
		t_lst 		*lst;
		int			promptlen;
		int			posx;
		int			posy;
		int			lenx;
		int			leny;
}					t_line;

int		debugtofile(t_line *line, char *s);
void	cursorright(t_line *line);
void	cursorleft(t_line *line);

int		def_term(void);
int		arrow(char *s, t_line *line);
char	readline();
char	printablekey(char *s);
void	printlast(t_lst *lst);

void 		printend(t_line *line);
void	delelem(t_line *line);
void	add(t_line *line, char a);
t_lst	*init(void);
void	lstdel(t_lst *lst);
int 	outc(int c);
void	movecursor(void);
void 	print(t_lst *line);
int		countlst(t_lst *lst);

#endif
