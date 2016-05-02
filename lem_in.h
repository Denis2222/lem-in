/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:55:44 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 04:19:48 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_ascii_screen
{
	char				**data;
	int					height;
	int					width;
}						t_screen;

typedef struct			s_room_wire
{
	struct s_li_wire	*wire;
	int					way;
	struct s_room_wire	*next;
}						t_rw;

typedef struct			s_dot
{
	int					x;
	int					y;
}						t_dot;

typedef struct			s_li_room
{
	char				*name;
	struct s_room_wire	*wires;
	struct s_li_room	*next;
	int					x;
	int					y;
	int					jump;
}						t_room;

typedef struct			s_li_wire
{
	t_room				*a;
	t_room				*b;
	int					power;
	int					antpass;
	struct s_li_wire	*next;
}						t_wire;

typedef struct			s_li_ant
{
	int					x;
	int					y;
	t_room				*room;
	struct s_li_ant		*next;
}						t_ant;

typedef struct			s_lem_in
{
	int					ant;
	t_room				*start;
	t_room				*end;
	t_room				*rooms;
	t_wire				*wires;
	t_wire				**usedwires;
	int					nbusedwires;
	t_ant				*ants;
	char				*opts;
	char				*stdin;
}						t_li;

t_li					*new_lemin(void);
void					read_lemin(t_li *li);
void					view(t_li *li);
void					check_lemin(t_li *li);
int						ft_streachr(char *str, int (f)(int));
void					viewstate(t_li *li);
int						readopts(int ac, char **av, char *opts, int i);

int						newroom(t_li *li, char *line, int flag);
int						addroom(t_li *li, t_room *room, int type);
t_room					*getroomptr(t_li *li, char *name,
						t_wire *wire, int way);
t_room					*rwtoroom(t_rw *rw);
t_room					*getroombyname(t_li *li, char *name);

void					addwireroom(t_room *room, t_wire *wire, int way);
int						newwire(t_li *li, char *line);
void					addwire(t_li *li, t_wire *wire);

int						isant(char *line);
int						isroom(char *line);
int						iswire(char *line);

void					spore(t_li *li);

int						ant_on_room(t_li *li, t_room *room);
int						get_nb_ant_on_room(t_li *li, t_room *room);
void					populate_ant(t_li *li);
void					ants_move(t_li *li);
void					ants_choose_move(t_li *li);
void					ant_move(t_li *li, t_ant *ant, t_rw *best, int nb);

int						lineparser(t_li *li, char *line);
int						lineparser2(t_li *li, char *line);
int						lineparserflag(t_li *li, char *line, int *flag);

t_dot					*dot(int x, int y);
void					tracewire(t_screen *screen, t_wire *wire);
void					draw_line(t_screen *screen, t_dot *p0,
									t_dot *p1, char c);

#endif
