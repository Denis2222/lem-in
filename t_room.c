/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:59:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 16:01:42 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		newroom(t_li *li, char *line, int flag)
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
	return (addroom(li, elem, flag));
}

int		addroom(t_li *li, t_room *room, int type)
{
	t_room	*current;

	current = li->rooms;
	if (!current)
		li->rooms = room;
	else
	{
		while (current->next)
		{
			if (ft_strequ(current->name, room->name))
				return (0);
			current = current->next;
		}
		current->next = room;
	}
	if (type == 1 && li->start != NULL)
		return (0);
	if (type == 1)
		li->start = room;
	if (type == 2 && li->end != NULL)
		return (0);
	if (type == 2)
		li->end = room;
	return (1);
}

void	addwireroom(t_room *room, t_wire *wire, int way)
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

int		get_nb_ant_on_room(t_li *li, t_room *room)
{
	t_ant	*ant;
	int		nb;

	nb = 0;
	ant = li->ants;
	while (ant)
	{
		if (ant->room == room)
			nb++;
		ant = ant->next;
	}
	return (nb);
}

int		ant_on_room(t_li *li, t_room *room)
{
	t_ant	*ant;

	ant = li->ants;
	while (ant)
	{
		if (ant->room == room)
			return (1);
		ant = ant->next;
	}
	return (0);
}
