/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:59:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 04:57:01 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isvalidnewroom(t_li *li, char *name, int flag)
{
	if (flag == 1 && li->start != NULL)
	{
		if (li->opts['v'])
			ft_printf("{red}Start already send{eoc}");
		return (0);
	}
	if (flag == 2 && li->end != NULL)
	{
		if (li->opts['v'])
			ft_printf("{red}End already send{eoc}\n");
		return (0);
	}
	if (getroombyname(li, name))
	{
		if (li->opts['v'])
			ft_printf("{red}Room : %s declared first{eoc}\n", name);
		return (0);
	}
	if (li->wires)
	{
		if (li->opts['v'])
			ft_printf("{red}Why ? Room after wire...{eoc}\n");
		return (0);
	}
	return (1);
}

int		newroom(t_li *li, char *line, int flag)
{
	t_room	*elem;
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (!isvalidnewroom(li, tab[0], flag))
	{
		ft_tabfree(tab);
		return (0);
	}
	elem = (t_room*)malloc(sizeof(t_room));
	elem->name = ft_strdup(tab[0]);
	elem->x = ft_atoi(tab[1]);
	elem->y = ft_atoi(tab[2]);
	elem->jump = -1;
	elem->wires = NULL;
	elem->next = NULL;
	ft_tabfree(tab);
	return (addroom(li, elem, flag));
}

int		addroom(t_li *li, t_room *room, int flag)
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
	if (flag == 1)
		li->start = room;
	if (flag == 2)
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
