/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 08:09:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void recurspore(t_li *li, t_room *room, int jump)
{
	t_rw *rw;

	if (room == li->start)
		return ;
	room->jump = jump;
	rw = room->wires;
	while (rw)
	{
		if (rwtoroom(rw)!= room &&
			(rwtoroom(rw)->jump == -1 || rwtoroom(rw)->jump > jump)
		)
		{
			rw->wire->power = jump;
			recurspore(li, rwtoroom(rw), jump + 1);
		}
		rw = rw->next;
	}
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
	recurspore(li, li->end, 0);
	if (!checkresolve(li))
	{
		ft_printf("ERROR");
		exit(0);
	}
}
