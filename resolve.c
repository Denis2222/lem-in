/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 12:39:50 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		checkdispersion(t_li *li, t_room *room)
{
	t_rw	*rw;
	t_room	*roomptr;
	int		dispersion;

	dispersion = 0;
	rw = room->wires;
	while (rw)
	{
		roomptr = rwtoroom(rw);
		if (roomptr && room != li->end)
		{
			if (roomptr != room &&
				(roomptr->jump < 0))
			{
				dispersion++;
			}
		}
		rw = rw->next;
	}
	if (dispersion < 2)
		dispersion = 0;
	return (dispersion);
}

void	recurspore(t_li *li, t_room *room, int jump)
{
	t_rw	*rw;
	t_room	*roomptr;
	int		dispersion;

	if (room == li->start)
		return ;
	room->jump = jump;
	dispersion = checkdispersion(li, room);
	rw = room->wires;
	while (rw)
	{
		roomptr = rwtoroom(rw);
		if (roomptr)
		{
			if (roomptr != room &&
				(roomptr->jump == -1 || roomptr->jump > jump))
			{
				rw->wire->power = jump + dispersion;
				recurspore(li, roomptr, jump + 1 + dispersion);
			}
		}
		rw = rw->next;
	}
	return ;
}

int		checkresolve(t_li *li)
{
	t_rw	*rw;

	rw = li->start->wires;
	while (rw)
	{
		if (rw->wire->power > -1)
			return (1);
		rw = rw->next;
	}
	return (0);
}

void	spore(t_li *li)
{
	recurspore(li, li->end, 1);
	if (!checkresolve(li))
	{
		ft_printf("ERROR\n");
		if (li->opts['v'])
			ft_printf("{red}No solution found{eoc}");
		exit(0);
	}
	populate_ant(li);
}

void	populate_ant(t_li *li)
{
	int		i;
	t_ant	*ant;
	t_ant	*current;

	i = li->ant;
	while (i > 0)
	{
		ant = (t_ant*)malloc(sizeof(t_ant));
		ant->room = li->start;
		ant->room->ants++;
		ant->x = li->start->x;
		ant->y = li->start->y;
		ant->next = NULL;
		if (!li->ants)
			li->ants = ant;
		else
		{
			current = li->ants;
			while (current->next)
				current = current->next;
			current->next = ant;
		}
		i--;
	}
}
