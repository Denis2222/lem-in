/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:30:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 04:19:49 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*rwtoroom(t_rw *rw)
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
			break ;
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
