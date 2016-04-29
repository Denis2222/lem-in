/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ant.c                                             :+:      :+:    :+:   */
/*                                                     +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 08:12:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	int		nb;

	nb = 0;
	ant = li->ants;
	while (ant)
	{
		if (ant->room == room)
			return (1);
		ant = ant->next;
	}
	return (0);
}

void 	populate_ant(t_li *li)
{
	int		i;
	t_ant 	*ant;
	t_ant	*current;

	i = li->ant;

	while (i > 0)
	{
		ant = (t_ant*)malloc(sizeof(t_ant));

		ant->room = li->start;

		ant->x = li->start->x;
		ant->y = li->start->y;
		ant->next = NULL;

		if (!li->ants)
			li->ants = ant;
		else
		{
			current = li->ants;
			while (current->next)
			{
				current = current->next;
			}
			current->next = ant;
		}
		i--;
	}
}

void ant_move(t_li *li, t_ant *ant, int nb)
{
	t_rw	*rw;
	t_room	*best;
	int		bestjump;

	best = NULL;
	bestjump = -10;
	if (ant->room == li->end)
		return ;
	rw = ant->room->wires;
	while (rw)
	{
		if (ant_on_room(li, rwtoroom(rw)) == 0 || rwtoroom(rw) == li->end)
		{
			if ((bestjump == -10 || bestjump > rw->wire->power) && rw->wire->power > -1)
			{
				bestjump = rw->wire->power;
				best = rwtoroom(rw);
			}
		}
		rw = rw->next;
	}
	if (best && bestjump >=0)
	{
		ft_printf("L%d-%s ", nb, best->name);
		ant->x = best->x;
		ant->y = best->y;
		ant->room = best;
	}
}

void 	ants_move(t_li *li)
{
	t_ant	*ant;
	int		nb;

	nb = 1;
	ant = li->ants;
	ft_printf("\n");
	while (ant)
	{
		ant_move(li, ant, nb);
		ant = ant->next;
		nb++;
	}
}
