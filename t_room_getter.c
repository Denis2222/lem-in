/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:30:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 15:31:35 by dmoureu-         ###   ########.fr       */
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
