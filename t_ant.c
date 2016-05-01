/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ant.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 15:47:31 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		checkunusedwires(t_li *li, t_wire *wire)
{
	int i;

	i = 0;
	while (i < li->nbusedwires)
	{
		if (li->usedwires[i] == wire)
			return (0);
		i++;
	}
	return (1);
}

int		ant_brain(t_li *li, t_ant *ant, t_rw *rw)
{
	int		total;
	int		current;
	t_rw	*choix;
	int		nbchoix;

	if (ant->room != li->start)
		return (1);
	current = rw->wire->power;
	total = 0;
	nbchoix = 0;
	choix = ant->room->wires;
	while (choix)
	{
		if (choix != rw && choix->wire->power < rw->wire->power &&
			choix->wire->power > -1)
		{
			total += choix->wire->power;
			nbchoix++;
		}
		choix = choix->next;
	}
	if (nbchoix > 0)
		if (get_nb_ant_on_room(li, li->start) < (current * nbchoix))
			return (0);
	return (1);
}

void	ant_move(t_li *li, t_ant *ant, t_rw *best, int nb)
{
	if (!li->opts['1'])
		ft_printf("L%d-%s ", nb, rwtoroom(best)->name);
	best->wire->antpass++;
	ant->x = rwtoroom(best)->x;
	ant->y = rwtoroom(best)->y;
	ant->room = rwtoroom(best);
	li->usedwires[li->nbusedwires] = best->wire;
	li->nbusedwires++;
}

void	ant_choose_move(t_li *li, t_ant *ant, int nb)
{
	t_rw	*rw;
	t_rw	*best;
	int		bestjump;

	best = NULL;
	bestjump = -10;
	if (ant->room == li->end)
		return ;
	rw = ant->room->wires;
	while (rw)
	{
		if ((ant_on_room(li, rwtoroom(rw)) == 0 || rwtoroom(rw) == li->end) &&
			checkunusedwires(li, rw->wire))
		{
			if ((bestjump == -10 || bestjump > rw->wire->power) &&
				rw->wire->power > -1 && ant_brain(li, ant, rw))
			{
				bestjump = rw->wire->power;
				best = rw;
			}
		}
		rw = rw->next;
	}
	if (best && bestjump >= 0)
		ant_move(li, ant, best, nb);
}

void	ants_move(t_li *li)
{
	t_ant	*ant;
	t_room	*room;
	int		nb;
	int		i;

	nb = 1;
	ant = li->ants;
	room = li->rooms;
	i = 0;
	while (i < li->nbusedwires)
	{
		li->usedwires[i] = NULL;
		i++;
	}
	li->nbusedwires = 0;
	if (!li->opts['1'])
		ft_printf("\n");
	while (ant)
	{
		ant_choose_move(li, ant, nb);
		ant = ant->next;
		nb++;
	}
}
