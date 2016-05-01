/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 12:26:29 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_li	*new_lem_in(void)
{
	t_li	*li;

	li = (t_li *)malloc(sizeof(t_li));
	li->ant = 0;
	li->start = NULL;
	li->end = NULL;
	li->rooms = NULL;
	li->wires = NULL;
	li->usedwires = NULL;
	li->nbusedwires = 0;
	li->ants = NULL;
	li->opts = ft_memalloc('z');
	li->stdin = NULL;
	return (li);
}

void 	ft_printf_each_room(t_room *first)
{
	t_room *room;
	t_rw 	*rw;

	room = first;
	ft_printf("\nroom list:\n==========\n{blue}");
	while (room)
	{
		ft_printf("\n -[%s] ", room->name);
		rw = room->wires;
		while (rw)
		{
			if (rwtoroom(rw))
				ft_printf("->%s", rwtoroom(rw)->name);
			else
				ft_printf("rw to no room %d", rw->way);
			rw = rw->next;
		}
		room = room->next;
	}
	ft_printf("{eoc}\n==========\n");
}


void 	ft_printf_each_wire(t_wire *first)
{
	t_wire *wire;
	wire = first;
	ft_printf("\nwire list:\n==========\n{green}");
	while (wire)
	{
		ft_printf(" %s - %s\n", wire->a->name, wire->b->name);
		wire = wire->next;
	}
	ft_printf("{eoc}==========\n");
}


void	viewstate(t_li *li)
{
	ft_printf("=============\n");
	ft_printf("Current lemin\n");
	ft_printf("=============\n");
	ft_printf("nb lemin: %d\n", li->ant);

	ft_printf("start room: %s\n", li->start->name);
	ft_printf("end room: %s\n", li->end->name);
	ft_printf_each_room(li->rooms);
 	ft_printf_each_wire(li->wires);
	ft_printf("=============\n");
}

int	lineparser(t_li *li, char *line)
{
	static int	flag = 0;

	if (isant(line))
	{
		li->ant = ft_atoi(line);
		return (1);
	}
	else if (ft_strequ(line, "##start"))
	{
		flag = 1;
		return (2);
	}
	else if (ft_strequ(line, "##end"))
	{
		flag = 2;
		return (3);
	}
	else if (ft_strncmp(line, "#", 1) == 0)
		return (4);
	else if (isroom(line))
	{
		if (newroom(li, line, flag))
		{
			flag = 0;
			return (5);
		}
	}
	else if (iswire(line))
		return (newwire(li, line));
	return (0);
}

void addstdin(t_li *li, char *line)
{
	char	*str;
	char	*tmp;

	str = li->stdin;
	if (!str)
		str = ft_strjoin("", line);
	else
	{
		tmp = str;
		str = ft_strjoin(str, "\n");
		free(tmp);
		tmp = NULL;
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		tmp = NULL;
	}
	li->stdin = str;
}

void	readlemin(t_li *li)
{
	int		ret;
	char	*line;
	int 	retour;

	retour = 0;
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		addstdin(li, line);
		retour = lineparser(li, line);
		if (retour == 0)
			break;
		free(line);
		line = NULL;
	}
	if (!li->rooms || !li->wires || !li->end || !li->start)
	{
		ft_printf("ERROR {red}[t_li parser]{eoc}\n");
		exit(0);
	}
	li->usedwires = (t_wire **)malloc(sizeof(t_wire) * li->ant);
	populate_ant(li);
}
