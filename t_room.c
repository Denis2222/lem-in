/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 05:30:47 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int newroom(t_li *li, char *line, int flag)
{
	t_room	*elem;
	char	**tab;

	tab = ft_strsplit(line, ' ');
	elem = (t_room*)malloc(sizeof(t_room));
	elem->name = ft_strdup(tab[0]);
	elem->x = ft_atoi(tab[1]);
	elem->y = ft_atoi(tab[2]);
	elem->jump = -1;
	elem->wires = NULL;
	elem->next = NULL;
	addroom(li, elem, flag);
	return (1);
}

void addroom(t_li *li, t_room *room, int type)
{

	t_room	*current;

	current = li->rooms;
	if (!current)
		li->rooms = room;
	else
	{
		while (current->next)
			current = current->next;
		current->next = room;
	}
	if (type == 1)
		li->start = room;
	if (type == 2)
		li->end = room;
}

void addwireroom(t_room *room, t_wire *wire, int way)
{
	t_rw	*current;
	t_rw	*rw;

	rw = (t_rw*)malloc(sizeof(t_rw));
	rw->next = NULL;
	rw->wire = wire;
	rw->way = way;

	current = room->wires;
	if (!current)
		room->wires = rw;
	else
	{
		while (current->next)
			current = current->next;
		current->next = rw;
	}
}

t_room *rwtoroom(t_rw *rw)
{
	if (rw->way)
		return (rw->wire->a);
	return (rw->wire->b);
}

t_room	*getroombyname(t_li *li, char *name)
{
	t_room	*current;

	current = li->rooms;
	while (current)
	{
		if (ft_strequ(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_room	*getroomptr(t_li *li, char *name, t_wire *wire, int way)
{
	t_room	*current;

	current = li->rooms;
	while (current)
	{
		if (ft_strequ(current->name, name))
			break;
		current = current->next;
	}
	if (current)
		if (ft_strequ(current->name, name))
		{
			addwireroom(current, wire, way);
			return (current);
		}
	ft_printf("\ngetroomptr pas content\n");
	return (NULL);
}
