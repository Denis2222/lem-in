/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:51:50 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 04:18:55 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_printf_each_room(t_room *first)
{
	t_room	*room;
	t_rw	*rw;

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

void	ft_printf_each_wire(t_wire *first)
{
	t_wire	*wire;

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
