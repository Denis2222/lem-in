/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 12:27:21 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void reorderroom(t_li *li)
{
	t_room	*room;
	int		i;

	i = 0;
	room = li->rooms;
	while (room)
	{
		room->y = i*2 + 5;
		room->x = room->jump*20 + 5;
		i++;
		room = room->next;
	}
}

void recurspore(t_li *li, t_room *room, int jump)
{
	t_rw 	*rw;
	t_room	*roomptr;

	if (room == li->start)
		return ;
	room->jump = jump;
	rw = room->wires;
	while (rw)
	{
		roomptr = rwtoroom(rw);
		if (roomptr)
		{
			if (roomptr != room &&
				(roomptr->jump == -1 || roomptr->jump > jump))
			{
				rw->wire->power = jump;
				recurspore(li, roomptr, jump + 1);
			}
		}
		rw = rw->next;
	}
	return ;
}

int 	checkresolve(t_li *li)
{
	t_rw 	*rw;

	rw = li->start->wires;
	while (rw)
	{
		if (rw->wire->power > -1)
			return (1);
		rw = rw->next;
	}
	return (0);
}

void 	spore(t_li *li)
{
	recurspore(li, li->end, 1);
	if (!checkresolve(li))
	{
		ft_printf("ERROR \n{red}No solution found{eoc}");
		exit(0);
	}
}
